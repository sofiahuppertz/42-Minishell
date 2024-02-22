/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_modify_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:58 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:39:11 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int modify_current_var(t_env *current, const char *var_name,
							  const char *new_value)
{
	if (ft_strncmp(current->str, var_name, ft_strlen(var_name)) == 0)
	{
		free(current->str);
		current->str = ft_strjoin(var_name, new_value);
		if (!current->str)
			return (1);
		return (0);
	}
	return (-42);
}

int e_modify_var(const char *new, const char *name, t_env **e)
{
	t_env *current;
	int alloc_d;
	int result;

	current = *e;
	alloc_d = 0;
	if (!name)
		return (-42);
	if (!new)
	{
		new = ft_strdup("");
		alloc_d = 1;
	}
	while (current)
	{
		result = modify_current_var(current, name, new);
		if (result != -42)
			return (result);
		current = current->next;
	}
	if (alloc_d)
		ft_memdel((void *)new);
	return (-42);
}
