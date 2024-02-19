/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:06 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 18:45:09 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	close_i_o(t_cmd_line **simple_cmd)
{
	if ((*simple_cmd)->fd_in != 0 && (*simple_cmd)->fd_in != -1)
		close((*simple_cmd)->fd_in);
	if ((*simple_cmd)->fd_out != 1 && (*simple_cmd)->fd_out != -1)
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
	close_fds(cmd_line);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	delete_cmd_line(cmd_line);
	delete_envp();
	exit(*status_pointer());
}

static void	exec_command(t_cmd_line **cmd_line, t_cmd_line **simple_cmd)
{
	dup2((*simple_cmd)->fd_in, STDIN_FILENO);
	dup2((*simple_cmd)->fd_out, STDOUT_FILENO);
	if ((*simple_cmd)->argv)
	{
		if (is_builtin((*simple_cmd)->argv[0]))
			handle_builtin(simple_cmd, cmd_line);
		else
		{
			close_fds(cmd_line);
			exec_binary((*simple_cmd)->argv, cmd_line);
		}
	}
	return ;
}

int	fork_and_exec(pid_t *pid, int idx, t_cmd_line **cmd_line,
		t_cmd_line **simple_cmd)
{
	pid[idx] = fork();
	if (pid[idx] == -1)
		exit(1);
	if (pid[idx] == 0)
	{
		redir(simple_cmd);
		rl_clear_history();
		ft_memdel((void *)pid);
		if (!(*stop_exec()))
			exec_command(cmd_line, simple_cmd);
		else
		{
			delete_envp();
			delete_cmd_line(cmd_line);
			exit(1);
		}
	}
	close_i_o(simple_cmd);
	return (0);
}
