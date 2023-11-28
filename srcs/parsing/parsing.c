/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:09 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 12:13:22 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	parsing(char **str, t_cmd_line **cmd_line)
{
	if (!syntax_ok(*str))
	{
		g_sig.status = 258;
		return (0);
	}
	if (!is_empty_line(*str))
	{
		add_spaces_to_delims(str);
		break_simple_cmds(*str, cmd_line);
		if (!(*cmd_line) || !tokenize(cmd_line))
			return (0);
		organize_redirections(cmd_line);
		expansions(cmd_line);
		token_list_to_array(cmd_line);
	}
	return (1);
}
