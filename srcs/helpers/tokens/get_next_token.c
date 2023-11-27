/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:39 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:42 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

t_token	*get_next_token(char *str, int *idx)
{
	t_token	*new_token;
	int		new_idx;
	char	open_quote;

	open_quote = ' ';
	new_idx = 0;
	new_token = create_node(get_token_length(str, *idx));
	if (!new_token)
		exit_failure();
	while (str[*idx] && (str[*idx] != ' ' || open_quote != ' '))
	{
		if (open_quote == ' ' && (str[*idx] == '\'' || str[*idx] == '\"'))
			open_quote = str[(*idx)++];
		else if (open_quote != ' ' && str[*idx] == open_quote)
		{
			open_quote = ' ';
			(*idx)++;
		}
		else
			new_token->str[new_idx++] = str[(*idx)++];
	}
	new_token->str[new_idx] = '\0';
	init_type(new_token);
	return (new_token);
}
