/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:07 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:15:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	r_stdin(t_cmd_line **s_cmd, t_token *t)
{
	if ((*s_cmd)->fd_in != 0 && (*s_cmd)->fd_in != -1)
		close((*s_cmd)->fd_in);
	(*s_cmd)->fd_in = open(t->str, O_RDONLY);
	if ((*s_cmd)->fd_in == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(t->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		*status_pointer() = 1;
		*stop_exec() = 1;
		return (-1);
	}
	return (0);
}
