/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:07 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:54:11 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	redirect_stdin(t_cmd_line **simple_cmd, t_token *token)
{
	if ((*simple_cmd)->fd_in != 0)
		close((*simple_cmd)->fd_in);
	(*simple_cmd)->fd_in = open(token->str, O_RDONLY);
	if ((*simple_cmd)->fd_in == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		g_sig.status = 1;
		g_sig.stop_exec = 1;
		return (-1);
	}
	return (0);
}
