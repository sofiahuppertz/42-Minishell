/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:58 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:15:07 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	redir_heredoc(t_cmd_line **s_cmd, t_token *t)
{
	if ((*s_cmd)->fd_in != 0 && (*s_cmd)->fd_in != -1)
		close((*s_cmd)->fd_in);
	(*s_cmd)->fd_in = create_heredoc(s_cmd, &t);
	if ((*s_cmd)->fd_in == -1)
	{
		ft_putstr_fd("minishell: Error creating heredoc", 2);
		*stop_exec() = 1;
		return (1);
	}
	return (0);
}
