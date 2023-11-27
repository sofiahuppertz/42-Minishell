/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:32:17 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:32:21 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	display_text(char *str)
{
	char	*start;

	start = str;
	if (str == NULL)
	{
		display_text("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return (str - start);
}
