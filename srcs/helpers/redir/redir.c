/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:49 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 13:24:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	r_heredoc(t_cmd_line **s_cmd)
{
	if ((*s_cmd)->fd_in != 0 && (*s_cmd)->fd_in != -1)
		close((*s_cmd)->fd_in);
	(*s_cmd)->fd_in = open((*s_cmd)->name_file, O_RDONLY);
	if ((*s_cmd)->fd_in == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((*s_cmd)->name_file, 2);
		ft_putendl_fd(": No such file or directory", 2);
		*status_pointer() = 1;
		*stop_exec() = 1;
		return (-1);
	}
	return (0);
}

int	redir(t_cmd_line **simple_cmd)
{
	t_token	*token;

	token = (*simple_cmd)->first_token;
	while (token)
	{
		if (token->type == FILE_IN)
			r_stdin(simple_cmd, token);
		else if (token->type == LIMIT)
			r_heredoc(simple_cmd);
		else if (token->type == FILE_TRUNC)
			r_stdout(simple_cmd, token, O_TRUNC);
		else if (token->type == FILE_APPEND)
			r_stdout(simple_cmd, token, O_APPEND);
		token = token->next;
	}
	return (0);
}
