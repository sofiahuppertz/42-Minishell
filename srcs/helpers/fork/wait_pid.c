/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/11 15:58:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int	idx;
	int	*status;

	idx = 0;
	if ((num_cmds == 1 && is_builtin((*cmd_line)->argv[0])) || *stop_exec())
	{
		return (0);
	}
	while (idx < num_cmds)
	{
		status = status_pointer();
		waitpid(pid[idx], status, 0);
		if (g_caught_signal != SIGINT && g_caught_signal != SIGQUIT)
		{
			if (WIFEXITED(*status))
				*status = WEXITSTATUS(*status);
			else
				*status = 1;
		}
		idx++;
	}
	return (0);
}
