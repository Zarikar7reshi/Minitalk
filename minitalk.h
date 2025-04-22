/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:29:19 by sabruma           #+#    #+#             */
/*   Updated: 2025/04/18 16:52:44 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./lib/printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line.h"
# define __USE_XOPEN_EXTENDED
# ifndef __USE_POSIX
#  define __USE_POSIX 1
# endif // !__USE_POSIX
# include <linux/types.h>
# include <signal.h>
# include <unistd.h>

void	send_message(pid_t to, char *msg_bits);
char	*convert_into_bits(char *msg);
void	chars_to_bits(char c, char *bits, int *i);

void	receive_messages(void);
void	decode(int signal);
void	print(void);

#endif // !MINITALK_H
