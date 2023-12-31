/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:30 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 20:44:11 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	init_envp(char **envp)
{
	t_env	**env;
	int		i;

	i = 0;
	env = get_adress_envp();
	while (envp && envp[i])
	{
		if (envp_add_var(envp[i], env) == -1)
			return (1);
		(*env)->declare = 0;
		i++;
	}
	init_shell_level();
	return (0);
}
