/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:31:46 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:31:51 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	check_format(va_list arguments, char format)
{
	if (format == 'c')
		return ((unsigned int)display_char(va_arg(arguments, int)));
	else if (format == '%')
		return (write(1, "%", 1));
	else if (format == 's')
		return (display_text(va_arg(arguments, char *)));
	else if (format == 'd' || format == 'i')
		return (display_integer(va_arg(arguments, int)));
	else if (format == 'u')
		return (display_unsigned_int(va_arg(arguments, unsigned int)));
	else if (format == 'p')
		return (display_pointer(va_arg(arguments, unsigned long long int)));
	else if (format == 'x' || format == 'X')
		return (display_hex_recursive(va_arg(arguments, unsigned int), format));
	return (0);
}
