/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_args_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:16 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:51:43 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	cmd_args_count(t_cmd_line *s_cmd, int *len)
{
	t_token	*token;

	*len = 0;
	token = s_cmd->first_token;
	while (token)
	{
		if (token->type == ARG || token->type == BUILTIN)
			*len += 1;
		token = token->next;
	}
	return ;
}
