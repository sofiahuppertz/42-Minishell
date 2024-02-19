/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 15:22:12 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	read_into_heredoc(int fd, char *limitor)
{
	char	*here_line;
	t_env	*envp;

	*cmd_in_progress() = 0;
	envp = *get_adress_envp();
	while (1)
	{
		*cmd_in_progress() = 0;
		here_line = readline("heredoc> ");
		if (here_line == NULL)
			return (0);
		if (g_caught_signal == SIGINT)
		{
			//rl_done = 1;
			break;
		}
		if (ft_strcmp(limitor, here_line) == 0)
			break ;
		if (here_line[0] != '\0')
			expand_cmd(&here_line, envp);
		ft_putendl_fd(here_line, fd);
		ft_memdel((void *)here_line);
	}
	*cmd_in_progress() = 1;
	ft_memdel((void *)here_line);
	return (0);
}
