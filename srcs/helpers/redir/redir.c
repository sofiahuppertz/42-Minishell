/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:49 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:53:27 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	redir(t_cmd_line **simple_cmd)
{
	t_token	*token;

	token = (*simple_cmd)->first_token;
	while (token)
	{
		if (token->type == FILE_IN)
			r_stdin(simple_cmd, token);
		else if (token->type == LIMIT)
			redir_heredoc(simple_cmd, token);
		else if (token->type == FILE_TRUNC)
			r_stdout(simple_cmd, token, O_TRUNC);
		else if (token->type == FILE_APPEND)
			r_stdout(simple_cmd, token, O_APPEND);
		token = token->next;
	}
	return (0);
}
