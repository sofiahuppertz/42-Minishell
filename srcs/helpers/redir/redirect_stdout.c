/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:13 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:54:17 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	redirect_stdout(t_cmd_line **cmdl, t_token *token, short int flag)
{
	if ((*cmdl)->fd_out != 1)
		close((*cmdl)->fd_out);
	(*cmdl)->fd_out = open(token->str, O_CREAT | O_RDWR | flag, 0644);
	if ((*cmdl)->fd_out == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(token->str, 2);
		ft_putendl_fd(": Permission denied", 2);
		g_sig.status = 1;
		g_sig.stop_exec = 1;
		return (1);
	}
	return (0);
}
