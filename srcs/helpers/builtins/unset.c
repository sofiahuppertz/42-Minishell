/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:13:24 by shuppert         ###   ########.fr       */
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
		if (ft_strncmp(env->str, value, len) == 0 && (env->str[len] == '\0'
				|| env->str[len] == '='))
			return (1);
		env = env->next;
	}
	return (0);
}

int	unset(const char **args)
{
	int	i;
	int	value_in_env;

	i = 1;
	if (!args[0])
		return (SUCCESS);
	while (args[i])
	{
		value_in_env = is_value_in_env(args[i]);
		if (value_in_env && ft_is_all(args[i], ft_isalnum))
			remove_var(args[i], get_adress_envp());
		i++;
	}
	envp_to_char();
	return (SUCCESS);
}
