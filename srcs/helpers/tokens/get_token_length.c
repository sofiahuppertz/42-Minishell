/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:45 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:16:01 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	get_token_length(char *str, int i)
{
	int		toklen;
	int		extra_quotes;
	char	c;

	toklen = 0;
	extra_quotes = 0;
	c = ' ';
	while (str[i + toklen])
	{
		if (str[i + toklen] == ' ' && c == ' ')
			break ;
		if (c == ' ' && (str[i + toklen] == '\'' || str[i + toklen] == '\"'))
			c = str[i + toklen];
		else if (c != ' ' && str[i + toklen] == c)
		{
			c = ' ';
			extra_quotes += 2;
		}
		toklen++;
	}
	toklen = toklen - extra_quotes + 1;
	return (toklen);
}
