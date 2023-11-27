/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:33:43 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/05 17:00:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	size_t	i;
	size_t	x;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	i = ft_strlen(s);
	new_string = (char *)malloc((i + 1) * sizeof(char));
	if (new_string == NULL)
	{
		return (NULL);
	}
	x = 0;
	while (x < i)
	{
		new_string[x] = f(x, s[x]);
		x++;
	}
	new_string[i] = '\0';
	return (new_string);
}
