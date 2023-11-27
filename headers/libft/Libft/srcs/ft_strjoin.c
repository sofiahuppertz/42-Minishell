/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:25:00 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/07 16:22:51 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len;

	if (!s1 || !s2)
		return NULL;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return NULL;

	ft_strcpy(str, s1);
	ft_strlcat(str, s2, len);

	return str;
}
