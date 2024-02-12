/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:41:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	unset(const char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		remove_var(args[i], get_adress_envp());
		i++;
	}
	return (SUCCESS);
}
