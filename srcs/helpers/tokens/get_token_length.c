/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:45 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:48 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	get_token_length(char *str, int i)
{
	int		token_len;
	int		extra_quotes;
	char	c;

	token_len = 0;
	extra_quotes = 0;
	c = ' ';
	while (str[i + token_len])
	{
		if (str[i + token_len] == ' ' && c == ' ')
			break ;
		if (c == ' ' && (str[i + token_len] == '\'' || str[i
				+ token_len] == '\"'))
			c = str[i + token_len];
		else if (c != ' ' && str[i + token_len] == c)
		{
			c = ' ';
			extra_quotes += 2;
		}
		token_len++;
	}
	token_len = token_len - extra_quotes + 1;
	return (token_len);
}
