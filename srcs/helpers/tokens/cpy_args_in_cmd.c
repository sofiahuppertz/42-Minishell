/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_args_in_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:22 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:24 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	cpy_args_in_cmd(t_cmd_line *simple_cmd)
{
	t_token	*token;
	int		i;

	token = simple_cmd->first_token;
	i = 0;
	while (token)
	{
		if (token->type == ARG || token->type == BUILTIN)
		{
			simple_cmd->argv[i] = token->str;
			i++;
		}
		token = token->next;
	}
	simple_cmd->argv[i] = NULL;
}
