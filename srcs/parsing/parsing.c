/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:09 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 19:05:35 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	parsing(char **str, t_cmd_line **cmd_line)
{
	if (!is_empty_line(*str))
	{
		if (!syntax_ok(*str))
		{
			*status_pointer() = 258;
			return (0);
		}
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
