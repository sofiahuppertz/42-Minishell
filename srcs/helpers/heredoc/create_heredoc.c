/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:18 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:38:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	create_heredoc(t_cmd_line **s_cmd, t_token **t)
{
	int		fd;
	char	*name_file;

	name_file = ".heredoc";
	fd = open(name_file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		perror("Error creating heredoc");
		return (-1);
	}
	read_into_heredoc(fd, (*t)->str);
	close(fd);
	fd = open(name_file, O_RDONLY);
	(*s_cmd)->fd_in = fd;
	if ((*s_cmd)->name_file != NULL)
	{
		unlink((*s_cmd)->name_file);
		ft_memdel((void *)(*s_cmd)->name_file);
	}
	(*s_cmd)->name_file = strdup(name_file);
	return (fd);
}
