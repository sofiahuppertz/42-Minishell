/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:30 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 13:05:49 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_sig	g_sig;

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_cmd_line	*full_cmd;

	full_cmd = NULL;
	str = NULL;
	init_envp(envp);
	g_sig.exit_shell = 0;
	g_sig.stop_exec = 0;
	while (!g_sig.exit_shell)
	{
		init_signals();
		read_command_line(&str);
		if (g_sig.exit_shell == 1)
		{
			ft_memdel((void *)str);
			break ;
		}
		g_sig.pid = 1;
		if (str != NULL)
			if (parsing(&str, &full_cmd) && full_cmd != NULL)
			{
				ft_memdel((void *)str);
				execution(&full_cmd);
			}
		delete_cmd_line(&full_cmd);
	}
	delete_envp();
	rl_clear_history();
	(void)argc;
	(void)argv;
	return (g_sig.status);
}
