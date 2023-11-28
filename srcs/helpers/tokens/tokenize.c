/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 11:33:21 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	str_to_tokens(t_cmd_line **simple_cmd, char *str)
{
	t_token	*arg;
	t_token	*prev_arg;
	int		index;

	if (!str || str[0] == '\0')
	{
		(*simple_cmd)->first_token = NULL;
		return (1);
	}
	index = 0;
	index = ft_add_while_true(index, str, &ft_iswhitespace);
	arg = get_next_token(str, &index);
	if (!arg)
		exit_failure();
	(*simple_cmd)->first_token = arg;
	prev_arg = arg;
	index = ft_add_while_true(index, str, &ft_iswhitespace);
	while (str && str[index])
	{
		arg = get_next_token(str, &index);
		if (!arg)
			exit_failure();
		prev_arg->next = arg;
		prev_arg = arg;
		index = ft_add_while_true(index, str, &ft_iswhitespace);
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
