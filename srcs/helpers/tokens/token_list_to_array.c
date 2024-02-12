/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:51 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:51:50 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	token_list_to_array(t_cmd_line **cmds)
{
	t_cmd_line	*simple_cmd;
	int			cmd_count;
	char		**new;

	simple_cmd = *cmds;
	while (simple_cmd)
	{
		cmd_args_count(simple_cmd, &cmd_count);
		new = malloc(sizeof(char *) * (cmd_count + 1));
		if (!new)
			exit_failure();
		simple_cmd->argv = new;
		cpy_args_in_cmd(simple_cmd);
		simple_cmd = simple_cmd->next;
	}
	return (0);
}
