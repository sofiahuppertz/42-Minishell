/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:41 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/11 17:37:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	handle_multiple_commands(int num_cmds, pid_t *pid,
		t_cmd_line ***cmd_line, t_cmd_line **simple_cmd)
{
	int	idx;

	idx = 0;
	while (idx < num_cmds)
	{
		fork_and_exec(pid, idx, *cmd_line, simple_cmd);
		*simple_cmd = (*simple_cmd)->next;
		idx++;
	}
}

int	dispatcher(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	t_cmd_line	*simple_cmd;
	int			*status;

	simple_cmd = *cmd_line;
	status = status_pointer();
	if (!*stop_exec())
	{
		simple_cmd = *cmd_line;
		if (num_cmds == 1 && is_builtin(simple_cmd->argv[0]))
		{
			redir(&simple_cmd);
			*status = exec_builtin((const char **)(*cmd_line)->argv,
					(*cmd_line)->fd_out, 0);
		}
		else
			handle_multiple_commands(num_cmds, pid, &cmd_line, &simple_cmd);
	}
	return (0);
}
