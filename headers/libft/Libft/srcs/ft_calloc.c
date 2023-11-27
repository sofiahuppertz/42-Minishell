/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/12 20:42:28 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_calloc(size_t elements, size_t size)
{
	void	*ptr;

	ptr = malloc(elements * size);
	if (!ptr)
		return (0x0);
	ft_memset(ptr, 0, elements * size);
	return ((void *)ptr);
}
