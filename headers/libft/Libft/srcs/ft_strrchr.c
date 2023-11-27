/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:59:55 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/06 17:36:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	char			*result;
	unsigned char	ch;

	i = ft_strlen(str);
	ch = c;
	result = NULL;
	while ((int)i >= 0)
	{
		if (str[i] == ch)
		{
			result = (char *)&str[i];
			return (result);
		}
		i--;
	}
	return (result);
}
