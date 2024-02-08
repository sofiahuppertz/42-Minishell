/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:53 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/08 12:59:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	create_pipes(t_cmd_line **cmd_line)
{
	t_cmd_line	*simple_cmd;
	int			**fds;
	int			file_idx;
	int			num_cmds;

	simple_cmd = *cmd_line;
	num_cmds = cmd_count(simple_cmd);
	fds = ft_calloc(sizeof(int *), num_cmds + 1);
	if (fds == NULL)
		exit_failure();
	fds[num_cmds] = NULL;
	file_idx = 0;
	while (simple_cmd)
	{
		make_pipe(fds, file_idx, simple_cmd);
		simple_cmd = simple_cmd->next;
		file_idx++;
	}
	delete_pipe_fds(fds);
	return (0);
}
