/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:32:11 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:32:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	display_integer(int num)
{
	long int	nbr;
	char		digit;
	int			idx;

	idx = 0;
	nbr = num;
	if (num < 0)
	{
		idx += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		digit = nbr + '0';
		idx += write(1, &digit, 1);
	}
	if (nbr >= 10)
	{
		idx += display_integer(nbr / 10);
		idx += display_integer(nbr % 10);
	}
	return (idx);
}
