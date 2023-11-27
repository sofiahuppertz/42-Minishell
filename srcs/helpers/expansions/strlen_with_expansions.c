/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_with_expansions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:21 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:51:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	strlen_with_expansions(const char *arg, t_env *env)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	while (arg[idx])
	{
		while (arg[idx] == EXPANSION)
		{
			idx++;
			if ((!arg[idx] || !ft_isalnum(arg[idx])) && arg[idx] != '?')
				len++;
			else
				len += strlen_expanded_var(arg, idx, env);
			if (!ft_isdigit(arg[idx]))
			{
				while (arg[idx + 1] && (ft_isalnum(arg[idx])
						|| arg[idx] == '_'))
					idx++;
			}
			else
				len -= 1;
		}
		len++;
		idx++;
	}
	return (len);
}
