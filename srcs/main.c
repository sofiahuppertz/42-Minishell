/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:30 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 12:24:41 by shuppert         ###   ########.fr       */
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
	return (*status_pointer());
}
