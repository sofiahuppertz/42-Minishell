/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:18 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 14:56:52 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static char *generate_random_filename(void)
{
	int rand_num;
	char *filename;
	char *prefix;
	char *random;

	srand((unsigned)time(NULL));
	rand_num = rand();
	prefix = ft_strdup(".file_");
	random = ft_itoa(rand_num);
	filename = ft_calloc((ft_strlen(prefix) + ft_strlen(random) + 1), sizeof(char));
	ft_strlcpy(filename, prefix, ft_strlen(prefix) + 1);
	ft_strlcat(filename, random, ft_strlen(random) + 1);
	ft_memdel((void *)prefix);
	ft_memdel((void *)random);

	return filename;
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