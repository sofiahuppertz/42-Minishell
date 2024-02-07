/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:58 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 19:14:16 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	redirect_heredoc(t_cmd_line **simple_cmd, t_token *token)
{
	if ((*simple_cmd)->fd_in != 0)
		close((*simple_cmd)->fd_in);
	(*simple_cmd)->fd_in = create_heredoc(simple_cmd, &token);
	if ((*simple_cmd)->fd_in == -1)
	{
		ft_putstr_fd("minishell: Error creating heredoc", 2);
		*stop_exec() = 1;
		return (1);
	}
	return (0);
}
