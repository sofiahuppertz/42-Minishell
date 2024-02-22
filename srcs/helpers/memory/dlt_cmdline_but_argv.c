/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlt_cmdline_but_argv.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:53 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/11 14:32:29 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void dlt_cmdline_but_argv(t_cmd_line **cmd_line)
{
	t_cmd_line *temp;

	if (cmd_line)
	{
		while (*cmd_line)
		{
			temp = (*cmd_line)->next;
			if ((*cmd_line)->string)
				ft_memdel((void *)(*cmd_line)->string);
			if ((*cmd_line)->first_token)
				delete_tokens((*cmd_line)->first_token);
			if ((*cmd_line)->name_file)
			{
				unlink((*cmd_line)->name_file);
				ft_memdel((*cmd_line)->name_file);
			}
			ft_memdel((*cmd_line));
			*cmd_line = temp;
		}
	}
	return;
}
