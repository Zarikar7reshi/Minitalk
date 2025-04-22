LIB = minitalk.a
FTPRINTF = ./lib/libftprintf.a#libft + printf
GNL = ./lib/libgnl.a#getnextline

FTPRINTF_NAME = libftprintf.a#libft + printf
GNL_NAME = libgnl.a#getnextline

# CFLAGS = -Wall -Wextra -Werror

CLIENT = client.c
SERVER = server.c
SRC = client_utils.c server_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) client server

client : $(LIB) $(FTPRINTF) $(GNL)
	cc $(CLIENT) $(LIB) $(FTPRINTF) $(GNL) -o client

server : $(LIB) $(FTPRINTF) $(GNL)
	cc $(SERVER) $(LIB) $(FTPRINTF) $(GNL) -o server

$(LIB): $(OBJ)
	ar -rcs $(LIB) $(OBJ)

$(OBJ): $(SRC)
	cc $(CFLAGS) -c $^

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
	rm -f $(LIB) $(FTPRINTF) $(GNL)
	$(MAKE) fclean -C ./lib/get_next_line
	$(MAKE) fclean -C ./lib/printf

re: fclean all

# bonus: all

.PHONY: all clean fclean re bonus client server
# cc server.c server_utils.c ./minitalk.a ./lib/libftprintf.a ./lib/libgnl.a -g -Wall -Wextra -Werror -o server
