/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:52:05 by sabruma           #+#    #+#             */
/*   Updated: 2025/04/18 16:51:41 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_bits;

// bits -> char*
void	receive_messages(void)
{
	g_bits = (char *)malloc(sizeof(char) * 8 + 1);
	if (!g_bits)
		return ;
	signal(SIGUSR1, decode);
	signal(SIGUSR2, decode);
	while (1)
		pause();
}

void	decode(int signal)
{
	static int	i = 0;

	if (signal == SIGUSR1)
	{
		g_bits[i] = 0;
		i++;
	}
	else if (signal == SIGUSR2)
	{
		g_bits[i] = 1;
		i++;
	}
	if (i == 8)
	{
		print();
		i = 0;
		g_bits[8] = '\0';
		free((void *)g_bits);
		g_bits = (char *)malloc(sizeof(int) * 8);
		if (!g_bits)
			return ;
	}
}

void	print(void)
{
	char	c;
	int		i;
	int		pow;

	c = '\0';
	i = 0;
	pow = 128;
	while (i <= 7)
	{
		c += g_bits[i] * pow;
		pow /= 2;
		i++;
	}
	ft_printf("%c", c);
}
