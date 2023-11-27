/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:47 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:51:48 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	close_fds(t_cmd_line **cmd_line)
{
	t_cmd_line	*simple_cmd;

	simple_cmd = *cmd_line;
	while (simple_cmd)
	{
		if (simple_cmd->fd_in != 0)
			close(simple_cmd->fd_in);
		if (simple_cmd->fd_out != 1)
			close(simple_cmd->fd_out);
		simple_cmd = simple_cmd->next;
	}
}
