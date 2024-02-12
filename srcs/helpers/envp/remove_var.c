/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:50:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	remove_var(const char *var_name, t_env **env)
{
	t_env	*previous;
	t_env	*current;
	size_t	var_name_len;

	current = *env;
	previous = NULL;
	var_name_len = ft_strlen(var_name);
	while (current)
	{
		if (ft_strncmp(current->str, var_name, var_name_len) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				*env = current->next;
			free(current->str);
			free(current);
			return (SUCCESS);
		}
		previous = current;
		current = current->next;
	}
	return (SUCCESS);
}
