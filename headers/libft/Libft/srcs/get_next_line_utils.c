/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:42:37 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/22 18:47:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int	check_for_newline(char *buffer, t_node **head)
{
	int		bit_idx;
	char	*temp;

	if (buffer == NULL)
	{
		return (1);
	}
	bit_idx = 0;
	temp = NULL;
	while (bit_idx < BUFFER_SIZE && buffer[bit_idx] != '\0')
	{
		if (buffer[bit_idx] == '\n')
		{
			temp = extract_from_buffer(buffer, bit_idx + 1);
			add_last_node(head, temp, bit_idx + 1);
			free(temp);
			return (1);
		}
		bit_idx++;
	}
	temp = extract_from_buffer(buffer, bit_idx);
	add_last_node(head, temp, bit_idx);
	free(temp);
	return (0);
}

char	*extract_from_buffer(char *buffer, int size)
{
	char	*extracted_string;
	char	temp;
	int		i;
	int		j;

	temp = 0;
	extracted_string = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (++i < size)
	{
		extracted_string[i] = buffer[i];
	}
	extracted_string[i] = '\0';
	j = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\0')
	{
		temp = buffer[i++];
		buffer[j++] = temp;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j++] = '\0';
	}
	return (extracted_string);
}

int	get_line_length(t_node **head)
{
	int		bytes_count;
	t_node	*ptr;
	int		i;

	if (*head == NULL)
	{
		return (-1);
	}
	bytes_count = 1;
	ptr = *head;
	i = 0;
	while (ptr != NULL && ptr->data[i] != '\n')
	{
		if (ptr->data[i] == '\0')
		{
			ptr = ptr->next;
			i = 0;
		}
		else
			i++;
		bytes_count++;
	}
	return (bytes_count);
}

char	*copy_line(t_node **head, int size)
{
	char	*new_line;
	t_node	*ptr;
	int		i;
	int		j;

	new_line = (char *)malloc(sizeof(char) * (size + 1));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (i < (size + 1))
		new_line[i++] = '\0';
	ptr = *head;
	i = 0;
	j = 0;
	while (ptr != NULL)
	{
		while (ptr->data[i] != '\0')
		{
			new_line[j++] = ptr->data[i++];
		}
		ptr = ptr->next;
		i = 0;
	}
	return (new_line);
}

int	add_last_node(t_node **head, char *data, int size)
{
	t_node	*new_node;
	t_node	*ptr;

	ptr = NULL;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (1);
	new_node->data = malloc(sizeof(char) * (size + 1));
	ft_strcpy(new_node->data, data);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	return (0);
}
