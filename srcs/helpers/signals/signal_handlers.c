/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 19:39:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	sigint_handler(int code)
{
	if (*cmd_in_progress() == 0)
	{
		ft_putstr_fd("\n", 2);
		*status_pointer() = 130;
		if (*get_heredoc_flag())
		{
			close(STDIN_FILENO);
		}
		else
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else
	{
		ft_putstr_fd("\n", 2);
		*status_pointer() = 130;
	}
	g_caught_signal = code;
}

void	sigquit_handler(int code)
{
	if (*cmd_in_progress() != 0)
	{
		ft_putstr_fd("\b\b  \b\b", 2);
		ft_putendl_fd("quit: (core dumped) ", 2);
		*status_pointer() = 131;
		g_caught_signal = code;
	}
	return ;
}
