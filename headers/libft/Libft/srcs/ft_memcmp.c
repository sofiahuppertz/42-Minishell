/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:38:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/09 15:25:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	int					result;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	result = 0;
	while (n-- > 0 && result == 0)
	{
		result = *p1++ - *p2++;
	}
	return (result);
}
