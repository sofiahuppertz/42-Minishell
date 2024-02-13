/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:51:42 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 21:35:05 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	process_command(char **str, t_cmd_line **full_cmd)
{
	*cmd_in_progress() = 1;
	if (*str != NULL)
	{
		if (parsing(str, full_cmd))
		{
			if (*full_cmd != NULL)
			{
				ft_memdel((void *)*str);
				execution(full_cmd);
			}
		}
	}
	delete_cmd_line(full_cmd);
}

void	run_shell()
{
	char		*str;
	t_cmd_line	*full_cmd;

	full_cmd = NULL;
	str = NULL;
	*exit_shell() = 0;
	*stop_exec() = 0;
	while (!*exit_shell())
	{
		init_signals();
		read_command_line(&str);
		if (*exit_shell() == 1)
		{
			ft_memdel((void *)str);
			break ;
		}
		process_command(&str, &full_cmd);
		*cmd_in_progress() = 0;
	}
}
