/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_is_valid_varname.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:49:41 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 21:49:08 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	envp_is_valid_varname(const char *varname)
{
	int	i;

	if (ft_isdigit(varname[0]) == 1)
		return (0);
	else if (varname[0] == '=')
		return (-3);
	i = 0;
	while (varname[i] && varname[i] != '=')
	{
		if (ft_isalnum(varname[i]) == 0)
			return (-1);
		i += 1;
	}
	if (varname[i] != '=')
		return (2);
	else if (varname[i] == '=' && varname[i + 1] == '\0')
		return (3);
	return (1);
}

