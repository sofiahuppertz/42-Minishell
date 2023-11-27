/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:02:10 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 14:49:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (n == 0)
		return (NULL);
	while (i <= n - little_len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (!ft_strncmp(&big[i], little, little_len))
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
