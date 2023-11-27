/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:08:55 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/22 18:47:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*newline;
	static char	_buff[BUFFER_SIZE];
	t_node		*lines;
	int			flag_line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	lines = NULL;
	flag_line = check_and_read_buffer(fd, _buff, &lines);
	if (flag_line == -1)
	{
		return (NULL);
	}
	count = get_line_length(&lines);
	if (count < 0)
	{
		return (NULL);
	}
	newline = finalize_line(&lines, count);
	return (newline);
}

int	check_and_read_buffer(int fd, char *buffer, t_node **lines)
{
	int	flag_line;

	flag_line = 0;
	if (buffer[0])
	{
		if (check_for_newline(buffer, lines))
			flag_line = 1;
	}
	while (flag_line != 1)
	{
		if (!(read(fd, buffer, BUFFER_SIZE)))
		{
			flag_line = 1;
			if (!(*lines))
			{
				return (-1);
			}
		}
		if (check_for_newline(buffer, lines))
		{
			flag_line = 1;
		}
	}
	return (flag_line);
}

char	*finalize_line(t_node **lines, int count)
{
	char	*line;

	line = copy_line(lines, count);
	free_list(*lines);
	return (line);
}

int	free_list(t_node *head)
{
	t_node	*current;
	char	*temp;

	while (head != NULL)
	{
		current = head;
		temp = current->data;
		head = head->next;
		free(temp);
		free(current);
	}
	return (0);
}

