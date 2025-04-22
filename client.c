/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:31:35 by sabruma           #+#    #+#             */
/*   Updated: 2025/04/18 16:35:38 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	main(int ac, char **av)
{
	char	*bits;

	if (ac != 3)
	{
		ft_printf("Error: invalid argument number");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(av[1]) < 0)
	{
		ft_printf("Error: pid can't be -1");
		exit(EXIT_FAILURE);
	}
	bits = convert_into_bits(av[2]);
	send_message(ft_atoi(av[1]), bits);
	return (0);
}
