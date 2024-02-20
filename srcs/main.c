/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:30 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/20 08:35:23 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

volatile sig_atomic_t	g_caught_signal;

int	main(int argc, char **argv, char **envp)
{
	init_envp(envp);
	run_shell();
	delete_envp();
	rl_clear_history();
	(void)argc;
	(void)argv;
	close(STDIN_FILENO);
	return (*status_pointer());
}
