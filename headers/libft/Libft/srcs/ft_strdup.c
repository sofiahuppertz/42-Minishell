/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:50:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/25 20:12:06 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char *ft_strdup(const char *s)
{
    char *dup = ft_calloc(sizeof(char), ft_strlen(s) + 1);
    if (dup)
        ft_strcpy(dup, s);
    return dup;
}