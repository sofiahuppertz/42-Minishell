/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:34 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:46:38 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	execution(t_cmd_line **full_cmd)
{
	t_cmd_line	*simple_cmd;
	pid_t		*pid;
	int			num_cmds;

	simple_cmd = *full_cmd;
	num_cmds = cmd_count(simple_cmd);
	create_pipes(full_cmd);
	pid = ft_calloc(sizeof(pid_t), num_cmds);
	if (pid == NULL)
		exit_failure();
	if (!g_sig.stop_exec)
	{
		dispatcher(full_cmd, pid, num_cmds);
		wait_pid(full_cmd, pid, num_cmds);
	}
	ft_memdel((void *)pid);
	g_sig.stop_exec = 0;
	return (0);
}
