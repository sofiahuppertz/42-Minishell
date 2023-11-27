/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:36 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:49:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

char	*envp_get_var(const char *var)
{
	int len;
	char *result;

	len = ft_strrchr(var, '=') - var + 1;
	result = ft_substr(var, 0, len);
	return (result);
}