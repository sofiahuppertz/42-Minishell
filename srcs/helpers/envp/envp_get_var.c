/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:36 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 17:54:30 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

char	*envp_get_var(const char *var)
{
	int		len;
	char	*result;

	len = ft_strrchr(var, '=') - var + 1;
	if (len < 1 || len == (int)ft_strlen(var))
		return (ft_strdup((var)));
	result = ft_substr(var, 0, len);
	return (result);
}
