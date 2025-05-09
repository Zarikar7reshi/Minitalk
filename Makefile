NAME = minitalk.a
FTPRINTF = ./lib/libftprintf.a#libft + printf
GNL = ./lib/libgnl.a#getnextline

FTPRINTF_NAME = libftprintf.a#libft + printf
GNL_NAME = libgnl.a#getnextline

CFLAGS = -Wall -Wextra -Werror

CLIENT = client.c
SERVER = server.c
SRC = client_utils.c server_utils.c
OBJ = $(SRC:.c=.o)

all: client server

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	cc $(CFLAGS) -c $^

client : $(NAME) $(FTPRINTF) $(GNL)
	cc $(CLIENT) $(NAME) $(FTPRINTF) $(GNL) $(CFLAGS) -o client

server : $(NAME) $(FTPRINTF) $(GNL)
	cc $(SERVER) $(NAME) $(FTPRINTF) $(GNL) $(CFLAGS) -o server

$(FTPRINTF):
	$(MAKE) -C ./lib/printf
	cp ./lib/printf/$(FTPRINTF_NAME) $(FTPRINTF)

$(GNL):
	$(MAKE) -C ./lib/get_next_line
	cp ./lib/get_next_line/$(GNL_NAME) $(GNL)

clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(CLIENT:.c=.o) $(SERVER:.c=.o)
	$(MAKE) clean -C ./lib/get_next_line
	$(MAKE) clean -C ./lib/printf

fclean:
	rm -f client server
	rm -f $(NAME) $(FTPRINTF) $(GNL)
	$(MAKE) fclean -C ./lib/get_next_line
	$(MAKE) fclean -C ./lib/printf

re: fclean all

# bonus: all

.PHONY: all clean fclean re bonus
# cc server.c server_utils.c ./minitalk.a ./lib/libftprintf.a ./lib/libgnl.a -g -Wall -Wextra -Werror -o server
