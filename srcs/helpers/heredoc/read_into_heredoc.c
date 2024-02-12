/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:23 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:33:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	read_into_heredoc(int fd, char *limitor)
{
	char	*here_line;
	t_env	*envp;

	envp = *get_adress_envp();
	while (1)
	{
		*cmd_in_progress() = 0;
		here_line = readline("> ");
		if (here_line == NULL)
			return (0);
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
