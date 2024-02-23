/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:45 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:14:17 by shuppert         ###   ########.fr       */
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
			if (token->type == ARG)
				expand_cmd(&(token->str), *get_adress_envp());
			token = token->next;
		}
		simple_cmd = simple_cmd->next;
	}
	return ;
}
