/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_modify_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:50:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_modify_var(const char *new_value, const char *var_name, t_env **env)
{
	t_env	*current;
	size_t	var_name_len;

	current = *env;
	var_name_len = ft_strlen(var_name);
	while (current)
	{
		if (ft_strncmp(current->str, var_name, var_name_len) == 0)
		{
			free(current->str);
			current->str = ft_strjoin(var_name, new_value);
			if (!current->str)
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (-42);
}
