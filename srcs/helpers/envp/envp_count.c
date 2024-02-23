/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:14 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:09:20 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_count(t_env *env)
{
	int	count;

	count = 1;
	while (env && env->next)
	{
		count++;
		env = env->next;
	}
	return (count);
}
