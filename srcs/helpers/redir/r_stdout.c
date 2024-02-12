/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:13 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:44:20 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	r_stdout(t_cmd_line **cmdl, t_token *t, short int f)
{
	if ((*cmdl)->fd_out != 1 && (*cmdl)->fd_out != -1)
		close((*cmdl)->fd_out);
	(*cmdl)->fd_out = open(t->str, O_CREAT | O_RDWR | f, 0644);
	if ((*cmdl)->fd_out == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(t->str, 2);
		ft_putendl_fd(": Permission denied", 2);
		*status_pointer() = 1;
		*stop_exec() = 1;
		return (1);
	}
	return (0);
}
