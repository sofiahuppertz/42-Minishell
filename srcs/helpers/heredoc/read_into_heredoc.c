/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 19:29:02 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	read_into_heredoc(int fd, char *limitor)
{
	char	*here_line;
	int		new_fd;
	t_env	*envp;

	envp = *get_adress_envp();
	new_fd = dup(STDIN_FILENO);
	*get_heredoc_flag() = 1;
	*cmd_in_progress() = 0;
	while (1)
	{
		here_line = readline("heredoc> ");
		if (here_line == NULL && g_caught_signal != SIGINT)
			return (0);
		if (g_caught_signal == SIGINT)
		{
			*stop_exec() = 1;
			dup2(new_fd, STDIN_FILENO);
			break ;
		}
		if (ft_strcmp(limitor, here_line) == 0)
			break ;
		if (here_line[0] != '\0')
			expand_cmd(&here_line, envp);
		ft_putendl_fd(here_line, fd);
		ft_memdel((void *)here_line);
	}
	*cmd_in_progress() = 1;
	*get_heredoc_flag() = 0;
	ft_memdel((void *)here_line);
	close(new_fd);
	return (0);
}
