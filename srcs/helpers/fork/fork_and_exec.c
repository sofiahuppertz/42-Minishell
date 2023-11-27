/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:06 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:52:08 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	fork_and_exec(pid_t *pid, int idx, t_cmd_line **cmd_line,
		t_cmd_line **simple_cmd)
{
	pid[idx] = fork();
	if (pid[idx] == -1)
		exit(1);
	if (pid[idx] == 0)
	{
		dup2((*simple_cmd)->fd_in, STDIN_FILENO);
		dup2((*simple_cmd)->fd_out, STDOUT_FILENO);
		close_fds(cmd_line);
		if ((*simple_cmd)->argv)
		{
			if (is_builtin((*simple_cmd)->argv[0]))
			{
				g_sig.status = exec_builtin((const char **)(*simple_cmd)->argv,
						(*simple_cmd)->fd_out);
				exit(g_sig.status);
			}
			else
				exec_binary((*simple_cmd)->argv, cmd_line);
		}
	}
	if ((*simple_cmd)->fd_in != 0)
		close((*simple_cmd)->fd_in);
	if ((*simple_cmd)->fd_out != 1)
		close((*simple_cmd)->fd_out);
	return (0);
}
