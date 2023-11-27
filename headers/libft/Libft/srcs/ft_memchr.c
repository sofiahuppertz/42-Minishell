/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:13:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/09 15:26:36 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	ch;
	unsigned char	*result;
	size_t			i;

	string = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	result = NULL;
	while (i < n)
	{
		if (string[i] == ch)
		{
			result = &string[i];
			return (result);
		}
		i++;
	}
	return (result);
}
