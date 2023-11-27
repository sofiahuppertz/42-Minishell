/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell_level.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:38 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:50:38 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	init_shell_level(void)
{
	int		shell_level;
	char	*temp;

	temp = envp_get_value("SHLVL", *get_adress_envp());
	if (temp)
	{
		if (!ft_is_all(temp, &ft_isdigit))
		{
			free(temp);
			return ;
		}
		shell_level = ft_atoi(temp);
		if (shell_level >= 0)
		{
			free(temp);
			temp = ft_itoa(shell_level + 1);
			envp_modify_var(temp, "SHLVL=", get_adress_envp());
		}
		free(temp);
	}
	else
		return ;
}
