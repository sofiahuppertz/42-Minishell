/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:47 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:57:46 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	exit_cmd(const char **cmd)
{
	g_sig.exit_shell = 1;
	ft_putendl_fd("exit 👋", 2);
	if (cmd[1] && ft_is_all(cmd[1], &ft_isdigit) && cmd[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		g_sig.exit_shell = 0;
		return (1);
	}
	else if (cmd[1])
	{
		if (!(ft_is_all(cmd[1], &ft_isdigit)))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd((char *)cmd[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			return (255);
		}
		else
			return (ft_atoi(cmd[1]));
	}
	return (0);
}
