/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:09 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 22:29:14 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	parsing(char **str, t_cmd_line **line)
{
	if (!syntax_ok(*str))
	{
		g_sig.status = 258;
		return (0);
	}
	if (!is_empty_line(*str))
	{
		add_spaces_to_delims(str);
		break_simple_cmds(*str, line);
		if (!tokenize(line))
			return (0);
		organize_redirections(line);
		expansions(line);
		token_list_to_array(line);
	}
	return (1);
}
