/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:47 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/08 11:09:36 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	print_numeric_arg_error(const char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd((char *)arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
	return (2);
}

int	exit_cmd(const char **cmd)
{
	int	arg_len;
	int	all_digit;

	if (cmd[1])
		arg_len = ft_strlen(cmd[1]);
	*exit_shell() = 1;
	ft_putendl_fd("exit 👋", 2);
	all_digit = ft_is_all(cmd[1], &ft_isdigit);
	if (cmd[1] && all_digit && cmd[2] && arg_len <= 20)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		*exit_shell() = 0;
		return (1);
	}
	else if (cmd[1])
	{
		if (!all_digit || arg_len > 20)
			return (print_numeric_arg_error((const char *)cmd[1]));
		else
			return (ft_atoi(cmd[1]));
	}
	return (0);
}
