/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:09 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 17:44:59 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	heredoc(t_cmd_line **simple_cmd)
{
	t_token		*token;
	t_cmd_line	*cmd;

	cmd = *simple_cmd;
	while (cmd)
	{
		token = cmd->first_token;
		while (token)
		{
			if (token->type == LIMIT)
				redir_heredoc(&cmd, token);
			token = token->next;
		}
		cmd = cmd->next;
	}
	return ;
}

int	parsing(char **str, t_cmd_line **cmd_line)
{
	if (!is_empty_line(*str))
	{
		if (!syntax_ok(*str))
		{
			*status_pointer() = 2;
			return (0);
		}
		add_spaces_to_delims(str);
		break_cmds(*str, cmd_line);
		if (!(*cmd_line) || !tokenize(cmd_line))
			return (0);
		organize_redirections(cmd_line);
		expansions(cmd_line);
		token_list_to_array(cmd_line);
		heredoc(cmd_line);
	}
	return (1);
}
