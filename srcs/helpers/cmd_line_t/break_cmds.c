/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:32 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 19:00:36 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	break_cmds(char *line, t_cmd_line **list)
{
	int	idx;
	int	cmd_start;

	idx = 0;
	cmd_start = 0;
	while (line[idx])
	{
		if (idx != 0)
		{
			idx++;
			cmd_start++;
		}
		strlen_simple_cmd(line, &idx);
		add_cmd_to_list(line, idx, cmd_start, list);
		cmd_start = idx;
		if (idx == 0)
		{
			idx++;
			cmd_start++;
		}
	}
	return (0);
}
