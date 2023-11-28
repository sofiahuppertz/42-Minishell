/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_add_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:50:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_add_var(const char *new_variable, t_env **env)
{
	t_env	*new_node;
	t_env	*current;

	new_node = ft_calloc(sizeof(t_env), 1);
	if (!env || !new_node)
		return (-1);
	new_node->str = ft_strdup(new_variable);
	if (!new_node->str)
		return (ERROR);
	new_node->next = NULL;
	if (*env == NULL)
		*env = new_node;
	else
	{
		current = *env;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (SUCCESS);
}
