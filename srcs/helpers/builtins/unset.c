/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 19:02:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	unset(const char **args)
{
	int		i;
	int		stop;
	char	*temp;

	i = 1;
	stop = 0;
	temp = NULL;
	while (args[i])
	{
		temp = e_get_val(args[i], *get_adress_envp());
		if (!envp_is_valid_varname(args[i]))
			stop = 1;
		else if (temp == NULL || ft_strcmp(temp, "") == 0)
			stop = 1;
		ft_memdel((void *)temp);
		if (!stop)
			remove_var(args[i], get_adress_envp());
		i++;
	}
	return (SUCCESS);
}
