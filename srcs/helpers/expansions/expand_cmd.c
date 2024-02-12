/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:54 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/09 17:52:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	handle_expansion_in_realloc(t_expansion *x, char **arg, t_env *envp)
{
	x->idx++;
	if (((*arg)[x->idx] == '\0' || !ft_isalnum((*arg)[x->idx]))
		&& (*arg)[x->idx] != '?')
		x->value[x->new_idx++] = '$';
	else
	{
		x->idx += strcpy_expanded_var(x, *arg, envp);
		while (ft_isalnum((*arg)[x->idx]) || (*arg)[x->idx] == '_')
			x->idx++;
	}
}

void	expand_cmd(char **arg, t_env *envp)
{
	t_expansion	x;
	int			new_len;

	new_len = len_w_exp((const char *)*arg, envp);
	x.value = ft_calloc(sizeof(char), new_len + 1);
	if (!x.value)
		exit_failure();
	x.new_idx = 0;
	x.idx = 0;
	while (x.new_idx < new_len && (*arg)[x.idx])
	{
		if ((*arg)[x.idx] == EXPANSION)
		{
			handle_expansion_in_realloc(&x, arg, envp);
			continue ;
		}
		x.value[x.new_idx++] = (*arg)[x.idx++];
	}
	x.value[x.new_idx] = '\0';
	free(*arg);
	*arg = x.value;
	return ;
}
