/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:45 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:50:50 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	expansions(t_cmd_line **cmd_line)
{
	t_cmd_line	*simple_cmd;
	t_token		*token;

	simple_cmd = *cmd_line;
	while (simple_cmd)
	{
		token = simple_cmd->first_token;
		while (token)
		{
			if (token->type == ARG || token->type == LIMIT)
				realloc_str_and_expansions(&(token->str), *get_adress_envp());
			token = token->next;
		}
		simple_cmd = simple_cmd->next;
	}
	return ;
}
