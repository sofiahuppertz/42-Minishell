/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_unsigned_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:32:27 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:32:31 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	display_unsigned_int(unsigned int num)
{
	int		idx;
	char	digit;

	idx = 0;
	if (num < 10)
	{
		digit = num + '0';
		idx = write(1, &digit, 1);
	}
	if (num >= 10)
	{
		idx += display_unsigned_int(num / 10);
		idx += display_unsigned_int(num % 10);
	}
	return (idx);
}
