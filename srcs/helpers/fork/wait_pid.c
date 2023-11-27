/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:10 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 21:31:57 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int	idx;

	idx = 0;
	if ((num_cmds == 1 && is_builtin((*cmd_line)->argv[0])) || g_sig.stop_exec)
	{
		return (0);
	}
	while (idx < num_cmds)
	{
		waitpid(pid[idx], &g_sig.status, 0);
		if (g_sig.sigint == 1 || g_sig.sigquit == 1)
			return (0);
		if (WIFEXITED(g_sig.status))
			g_sig.status = WEXITSTATUS(g_sig.status);
		else
			g_sig.status = 1;
		idx++;
	}
	return (0);
}
