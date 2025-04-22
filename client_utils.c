/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:52:05 by sabruma           #+#    #+#             */
/*   Updated: 2025/04/18 16:46:49 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char* -> bits
void	send_message(pid_t to, char *msg_bits)
{
	char	*tmp;

	tmp = msg_bits;
	while (msg_bits && *msg_bits)
	{
		if (*msg_bits == '0')
			kill(to, SIGUSR1);
		else if (*msg_bits == '1')
			kill(to, SIGUSR2);
		msg_bits++;
		usleep(70);
	}
	free(tmp);
}

char	*convert_into_bits(char *msg)
{
	char	*bits;
	int		i;
	int		j;
	int		msg_len;

	msg_len = ft_strlen(msg);
	i = 0;
	j = 0;
	bits = (char *)malloc(sizeof(char) * msg_len * 8 + 1);
	if (!bits)
		return (NULL);
	while (j < msg_len)
	{
		chars_to_bits(msg[j], bits, &i);
		j++;
	}
	bits[i] = '\0';
	return (bits);
}

void	chars_to_bits(char c, char *bits, int *i)
{
	int	j;
	int	val;

	j = 7;
	while (j >= 0)
	{
		val = (c & (1 << (7 - j)));
		if (val)
			bits[*i + j] = '1';
		else
			bits[*i + j] = '0';
		j--;
	}
	*i += 8;
}
