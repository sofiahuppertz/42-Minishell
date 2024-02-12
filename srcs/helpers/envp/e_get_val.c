/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_get_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:28 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:49:29 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

char	*e_get_val(const char *var_name, t_env *env)
{
	t_env	*current;
	char	*str;
	size_t	len;

	current = env;
	len = ft_strlen(var_name);
	while (current)
	{
		if (ft_strncmp(current->str, var_name, len) == 0 && current->str[len] == '=')
		{
			str = current->str;
			while (*str != '=')
				str++;
			if (*(str + 1) == '\0')
				return (ft_strdup(""));
			return (ft_strdup(str + 1));
		}
		current = current->next;
	}
	return (NULL);
}
