/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:30 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 20:31:42 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_sig	g_sig;

int	main(int argc, char **argv, char **envp)
{
	init_envp(envp);
	run_shell();
	delete_envp();
	//rl_clear_history();
	(void)argc;
	(void)argv;
	return (g_sig.status);
}
