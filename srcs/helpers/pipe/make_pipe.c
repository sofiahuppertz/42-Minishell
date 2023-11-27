/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:06 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:53:09 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	make_pipe(int **fds, int idx, t_cmd_line *simple_cmd)
{
	fds[idx] = ft_calloc(sizeof(int), 2);
	if (fds[idx] == NULL)
		exit_failure();
	if (pipe(fds[idx]) == -1)
		return (1);
	if (idx == 0)
		simple_cmd->fd_in = 0;
	else
		simple_cmd->fd_in = fds[idx - 1][0];
	if (simple_cmd->next == NULL)
	{
		close(fds[idx][0]);
		close(fds[idx][1]);
		simple_cmd->fd_out = 1;
	}
	else
		simple_cmd->fd_out = fds[idx][1];
	return (0);
}
