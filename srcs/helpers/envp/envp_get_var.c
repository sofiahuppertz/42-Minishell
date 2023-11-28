/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:36 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:16:01 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

char	*envp_get_var(const char *var)
{
	int		len;
	char	*result;
	
	len = ft_strrchr(var, '=') - var + 1;
	result = ft_substr(var, 0, len);
	return (result);
}
