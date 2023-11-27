/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args_in_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:16 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	count_args_in_cmd(t_cmd_line *simple_cmd, int *len)
{
	t_token	*token;

	*len = 0;
	token = simple_cmd->first_token;
	while (token)
	{
		if (token->type == ARG || token->type == BUILTIN)
			*len += 1;
		token = token->next;
	}
	return ;
}
