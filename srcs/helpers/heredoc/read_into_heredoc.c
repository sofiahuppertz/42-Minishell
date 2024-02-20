/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/20 10:15:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	process_line(char **line, int fd)
{
	t_env	*envp;

	envp = *get_adress_envp();
	if ((*line)[0] != '\0')
		expand_cmd(line, envp);
	ft_putendl_fd(*line, fd);
	ft_memdel((void *)*line);
}

static void	change_flags(void)
{
	if (*get_heredoc_flag() == 0)
	{
		*get_heredoc_flag() = 1;
	}
	else
	{
		*get_heredoc_flag() = 0;
	}
	if (*cmd_in_progress() == 0)
	{
		*cmd_in_progress() = 1;
	}
	else
	{
		*cmd_in_progress() = 0;
	}
}

int	read_into_heredoc(int fd, char *limitor)
{
	char	*line;
	int		new_fd;

	new_fd = dup(STDIN_FILENO);
	change_flags();
	while (1)
	{
		line = readline("heredoc> ");
		if (line == NULL && g_caught_signal != SIGINT)
			return (0);
		if (g_caught_signal == SIGINT)
		{
			*stop_exec() = 1;
			dup2(new_fd, STDIN_FILENO);
			break ;
		}
		if (ft_strcmp(limitor, line) == 0)
			break ;
		process_line(&line, fd);
	}
	change_flags();
	ft_memdel((void *)line);
	close(new_fd);
	return (0);
}
