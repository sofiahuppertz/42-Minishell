/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:10 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 19:14:16 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int	idx;

	idx = 0;
	if ((num_cmds == 1 && is_builtin((*cmd_line)->argv[0])) || *stop_exec())
	{
		return (0);
	}
	while (idx < num_cmds)
	{
		waitpid(pid[idx], &*status_pointer(), 0);
		if (g_sig.sigint == 1 || g_sig.sigquit == 1)
			return (130);
		if (WIFEXITED(*status_pointer))
			*status_pointer() = WEXITSTATUS(*status_pointer());
		else
			*status_pointer() = 1;
		idx++;
	}
	return (0);
}
