/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_is_value_in_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:23:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 22:20:31 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_is_value_in_env(const char *value)
{
	t_env	*env;
	int		len;

	env = *get_adress_envp();
	len = ft_strlen(value);
	while (env)
	{
		if (ft_strncmp(env->str, value, len) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}
