/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:57:37 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	unset(const char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		envp_remove_var(args[i], get_adress_envp());
		i++;
	}
	return (SUCCESS);
}
