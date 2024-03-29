/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_w_exp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:21 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 13:03:31 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	handle_expansion(const char *arg, int *idx, int *len, t_env *env)
{
	(*idx)++;
	if ((!arg[*idx] || !ft_isalnum(arg[*idx])) && arg[*idx] != '?')
		(*len)++;
	else
		*len += strlen_expanded_var(arg, *idx, env);
	if (!ft_isdigit(arg[*idx]))
	{
		while (arg[*idx + 1] && (ft_isalnum(arg[*idx]) || arg[*idx] == '_'))
			(*idx)++;
	}
	else
		(*len)--;
}

int	len_w_exp(const char *arg, t_env *env)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] == EXPANSION)
		{
			handle_expansion(arg, &idx, &len, env);
			continue ;
		}
		len++;
		idx++;
	}
	return (len);
}
