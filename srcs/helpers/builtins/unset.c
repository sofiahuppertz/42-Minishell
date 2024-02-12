/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:11 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 22:33:19 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void handle_unset_error(const char *var, int *stop)
{
	*stop = 1;
	if (!ft_isdigit(var[0]) && ft_is_all(var, ft_isalnum))
		return;
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd((char *)var, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	unset(const char **args)
{
	int	i;
	int stop;
	char *temp;

	i = 1;
	stop = 0;
	temp = NULL;
	while (args[i])
	{
		temp = e_get_val(args[i], *get_adress_envp());
		if (!envp_is_valid_varname(args[i]))
			handle_unset_error(args[i], &stop);
		else if (temp == NULL || ft_strcmp(temp, "") == 0)
			handle_unset_error(args[i], &stop);
		ft_memdel((void *)temp);
		if (!stop)
			remove_var(args[i], get_adress_envp());
		i++;
	}
	return (SUCCESS);
}
