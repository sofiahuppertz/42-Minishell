/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cmd_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:48 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 18:21:27 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	delete_cmd_line(t_cmd_line **cmd_line)
{
	t_cmd_line	*temp;

	if (cmd_line)
	{
		while (*cmd_line)
		{
			temp = (*cmd_line)->next;
			close_fds(cmd_line);
			if ((*cmd_line)->string)
				ft_memdel((void *)(*cmd_line)->string);
			if ((*cmd_line)->argv)
				ft_memdel_2d((void **)(*cmd_line)->argv);
			if ((*cmd_line)->first_token)
				delete_tokens((*cmd_line)->first_token);
			if ((*cmd_line)->name_file)
				ft_memdel((*cmd_line)->name_file);
			ft_memdel((*cmd_line));
			*cmd_line = temp;
		}
	}
	return ;
}
