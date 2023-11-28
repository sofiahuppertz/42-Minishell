/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_modify_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:58 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 21:06:56 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_modify_var(const char *new_value, const char *var_name, t_env **env)
{
	t_env	*current;
	size_t	var_name_len;
	int 	alloc_d;

	current = *env;
	alloc_d = 0;
	if (!var_name)
		return (-42);
	if (!new_value)
	{
		new_value = ft_strdup("");
		alloc_d = 1;
	}
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
	if (alloc_d)
		ft_memdel((void *)new_value);
	return (-42);
}
