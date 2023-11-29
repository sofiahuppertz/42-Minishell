/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_print_sorted_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:18 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 12:44:04 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	envp_print_sorted_env(t_env *env, int fd)
{
	char	**sorted_env;
	int		var;

	var = 0;
	sorted_env = envp_sort(env);
	while (sorted_env[var])
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putendl_fd(sorted_env[var], fd);
		var++;
	}
	ft_memdel_2d((void **)sorted_env);
	return ;
}
