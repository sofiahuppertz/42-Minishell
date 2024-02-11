/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/11 17:40:05 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	close_input_output(t_cmd_line **simple_cmd)
{
	if ((*simple_cmd)->fd_in != 0)
		close((*simple_cmd)->fd_in);
	if ((*simple_cmd)->fd_out != 1)
		close((*simple_cmd)->fd_out);
	return ;
}

static void	handle_builtin(t_cmd_line **simple_cmd, t_cmd_line **cmd_line)
{
	const char	**args;
	int			*status;

	status = status_pointer();
	args = (const char **)(*simple_cmd)->argv;
	*status = exec_builtin(args, (*simple_cmd)->fd_out, 1);
	delete_cmd_line(cmd_line);
	delete_envp();
	exit(*status_pointer());
}

int	fork_and_exec(pid_t *pid, int idx, t_cmd_line **cmd_line,
		t_cmd_line **simple_cmd)
{
	pid[idx] = fork();
	if (pid[idx] == -1)
		exit(1);
	if (pid[idx] == 0)
	{
		rl_clear_history();
		ft_memdel((void *)pid);
		redir(simple_cmd);
		if (!(*stop_exec()))
		{
			dup2((*simple_cmd)->fd_in, STDIN_FILENO);
			dup2((*simple_cmd)->fd_out, STDOUT_FILENO);
			close_fds(cmd_line);
			if ((*simple_cmd)->argv)
			{
				if (is_builtin((*simple_cmd)->argv[0]))
					handle_builtin(simple_cmd, cmd_line);
				else
					exec_binary((*simple_cmd)->argv, cmd_line);
			}
		}
		else
			exit(1);
	}
	close_input_output(simple_cmd);
	return (0);
}
