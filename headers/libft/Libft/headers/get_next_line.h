/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:07:56 by shuppert          #+#    #+#             */
/*   Updated: 2023/06/22 18:46:59 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct node_t
{
	char			*data;
	struct node_t	*next;
}					t_node;

int					add_last_node(t_node **head, char *data, int size);
int					check_and_read_buffer(int fd, char *buffer, t_node **lines);
int					check_for_newline(char *buffer, t_node **head);
char				*copy_line(t_node **head, int size);
char				*extract_from_buffer(char *buffer, int size);
char				*finalize_line(t_node **lines, int count);
int					free_list(t_node *head);
int					get_line_length(t_node **head);
char				*get_next_line(int fd);

#endif
