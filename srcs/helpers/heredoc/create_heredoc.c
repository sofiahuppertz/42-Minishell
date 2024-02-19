/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:18 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 13:45:38 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	create_heredoc(t_cmd_line **s_cmd, t_token **t)
{
	int		fd;
	char	*filename;
	int		rand_num;
	char	*prefix;
	char	*temp;

	srand((unsigned)time(NULL));
	rand_num = rand();
	prefix = ft_strdup(".file_");
	temp = ft_itoa(rand_num);
	filename = ft_calloc((ft_strlen(prefix) + ft_strlen(temp)), sizeof(char));
	ft_strlcpy(filename, prefix, ft_strlen(prefix));
	ft_strlcat(filename, temp, ft_strlen(temp));
	ft_memdel((void *)prefix);
	ft_memdel((void *)temp);
	ft_putstr_fd(filename, 1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		perror("Error creating heredoc");
		return (-1);
	}
	read_into_heredoc(fd, (*t)->str);
	close(fd);
	ft_putstr_fd((*s_cmd)->name_file, 1);
	//if ((*s_cmd)->name_file != NULL)
	//{
	//	unlink((*s_cmd)->name_file);
	//	ft_memdel((void *)(*s_cmd)->name_file);
	//}
	(*s_cmd)->name_file = filename;
	return (fd);
}
