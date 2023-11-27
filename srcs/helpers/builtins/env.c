/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:31 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:58:00 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	env(t_env *env, int fd)
{
	while (env && env->next)
	{
		if (envp_is_value_assigned(env->str))
			ft_putendl_fd(env->str, fd);
		env = env->next;
	}
	if (env)
		ft_putendl_fd(env->str, fd);
	return (SUCCESS);
}
