/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:31:35 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:31:40 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	display_ptr_recursive(unsigned long long int num)
{
	int		idx;
	char	digit;

	idx = 0;
	if (num < 16)
	{
		if (num >= 10)
			digit = num - 10 + 'a';
		else
			digit = num + '0';
		return (write(1, &digit, 1));
	}
	if (num >= 16)
	{
		idx += display_ptr_recursive(num / 16);
		idx += display_ptr_recursive(num % 16);
	}
	return (idx);
}

int	display_pointer(unsigned long long int num)
{
	int	count;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		count = ft_printf("0x");
		count += display_ptr_recursive(num);
	}
	return (count);
}
