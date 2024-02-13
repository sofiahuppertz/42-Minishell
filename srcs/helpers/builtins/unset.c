/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 22:21:58 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	is_value_in_env(const char *value)
{
	t_env	*env;
	int		len;

	env = *get_adress_envp();
	len = ft_strlen(value);
	while (env)
	{
		if (ft_strncmp(env->str, value, len) == 0 
			&& (env->str[len] == '\0' || env->str[len] == '='))
			return (1);
		env = env->next;
	}
	return (0);
}

int	unset(const char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		int value_in_env = is_value_in_env(args[i]);
		if (value_in_env && ft_is_all(args[i], ft_isalnum))
			remove_var(args[i], get_adress_envp());
		i++;
	}
	return (SUCCESS);
}
