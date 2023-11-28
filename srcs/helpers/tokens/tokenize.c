/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 12:19:38 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static t_token *get_next_arg(char *str, int *index)
{
	t_token *arg;

	*index = ft_add_while_true(*index, str, &ft_iswhitespace);
	if (!str[*index])
		return NULL;
	arg = get_next_token(str, index);
	if (!arg)
		exit_failure();
	return arg;
}

static int str_to_tokens(t_cmd_line **simple_cmd, char *str)
{
	t_token *arg;
	t_token *prev_arg;
	int index;

	if (!str || str[0] == '\0')
	{
		(*simple_cmd)->first_token = NULL;
		return (1);
	}
	index = 0;
	arg = get_next_arg(str, &index);
	(*simple_cmd)->first_token = arg;
	prev_arg = arg;
	while ((arg = get_next_arg(str, &index)) != NULL)
	{
		prev_arg->next = arg;
		prev_arg = arg;
	}
	if (prev_arg)
		prev_arg->next = NULL;
	return (1);
}

int	tokenize(t_cmd_line **cmd_list)
{
	t_cmd_line	*simple_cmd;

	simple_cmd = *cmd_list;
	while (simple_cmd)
	{
		if (!str_to_tokens(&simple_cmd, simple_cmd->string))
			return (0);
		simple_cmd = simple_cmd->next;
	}
	return (1);
}
