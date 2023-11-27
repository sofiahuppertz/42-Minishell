/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:30 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 21:45:34 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_sig	g_sig;

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_cmd_line	*full_cmd;

	full_cmd = NULL;
	init_envp(envp);
	while (!g_sig.exit_shell)
	{
		init_signals();
		read_command_line(&str);
		if (g_sig.exit_shell == 1)
			break ;
		g_sig.pid = 1;
		if (str != NULL)
			parsing(&str, &full_cmd);
		if (g_sig.status != 258 && full_cmd != NULL)
			execution(&full_cmd);
		ft_memdel((void *)str);
		delete_cmd_line(&full_cmd);
	}
	delete_envp();
	(void)argc;
	(void)argv;
	return (g_sig.status);
}
