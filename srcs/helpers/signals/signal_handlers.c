/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:47 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:44:01 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_sig.status = 1;
	}
	else
	{
		ft_putstr_fd("\n", 2);
		g_sig.status = 130;
	}
	g_sig.sigint = 1;
}

void	sig_quit(int code)
{
	(void)code;
	if (g_sig.pid != 0)
	{
		ft_putstr_fd("\b\b  \b\b", 2);
		ft_putendl_fd("quit: (core dumped) ", 2);
		g_sig.status = 131;
		g_sig.sigquit = 1;
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}
