/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:00 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 11:40:42 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	print_pipe_error(void)
{
	ft_putstr_fd("minishell: syntax error near: unexpected token `|'\n", 2);
	return (1);
}

int	duplicate_pipes(char *str)
{
	int	idx;
	int	pipe;

	idx = 0;
	pipe = 0;
	while (str[idx])
	{
		if (str[idx] != ' ' && str[idx] != '|')
			pipe = 1;
		if (str[idx] == '|')
		{
			if (pipe == 0 && !find_open_quotes(str, idx))
				return (print_pipe_error());
			pipe = 0;
		}
		idx += 1;
	}
	if (idx > 0)
		idx -= 1;
	while (idx >= 0 && ft_iswhitespace(str[idx]))
		idx -= 1;
	if (str[idx] == '|')
		return (print_pipe_error());
	return (0);
}
