/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 21:14:01 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int idx;
	int *status;

	idx = 0;
	if ((num_cmds == 1 && is_builtin((*cmd_line)->argv[0])) || *stop_exec())
	{
		return (0);
	}
	while (idx < num_cmds)
	{
		status = status_pointer();
		waitpid(pid[idx], status, 0);
		if (caught_signal == 2 || caught_signal == 3)
			*status = 130;
		else if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		else
			*status = 1;
		idx++;
	}
	return (0);
}
