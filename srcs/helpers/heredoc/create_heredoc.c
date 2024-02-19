/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:18 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 19:33:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static char	*generate_random_filename(void)
{
	int		temp;
	char	*res;
	char	*prefix;
	char	*random;

	srand((unsigned)time(NULL));
	temp = rand();
	prefix = ft_strdup(".file_");
	random = ft_itoa(temp);
	temp = ft_strlen(prefix) + ft_strlen(random) + 1;
	res = ft_calloc(temp, sizeof(char));
	ft_strlcpy(res, prefix, ft_strlen(prefix) + 1);
	ft_strlcat(res, random, ft_strlen(random) + 1);
	ft_memdel((void *)prefix);
	ft_memdel((void *)random);
	return (res);
}

int	create_heredoc(t_cmd_line **s_cmd, t_token **t)
{
	int		fd;
	char	*filename;

	filename = generate_random_filename();
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		perror("Error creating heredoc");
		return (-1);
	}
	read_into_heredoc(fd, (*t)->str);
	close(fd);
	(*s_cmd)->name_file = filename;
	return (fd);
}
