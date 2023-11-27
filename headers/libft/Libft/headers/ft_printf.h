/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:49:33 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 15:07:16 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	check_format(va_list arguments, char formaclet);
int	display_char(unsigned int n);
int	display_hex_recursive(unsigned int num, char c);
int	display_integer(int num);
int	display_ptr_recursive(unsigned long long int num);
int	display_pointer(unsigned long long int num);
int	display_text(char *str);
int	display_unsigned_int(unsigned int num);

#endif
