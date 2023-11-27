/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_is_value_assigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:46 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:49:48 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_is_value_assigned(const char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (ptr && *(ptr + 1) != '\0')
		return (1);
	return (0);
}
