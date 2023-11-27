/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:32:35 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/27 13:32:40 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	str_array_length(const char **str_array)
{
	size_t	i;

	i = 0;
	while (str_array[i] != 0)
	{
		i++;
	}
	return (i);
}
