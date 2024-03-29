/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:38 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/19 19:27:49 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	exec_builtin(const char **cmd_lst, int fd, int child)
{
	int	result;

	result = 1;
	if (!(*stop_exec()))
	{
		if (!cmd_lst || !(*cmd_lst))
			return (0);
		if (!ft_strcmp(cmd_lst[0], "exit") && !child)
			result = exit_cmd(cmd_lst);
		else if (!ft_strcmp(cmd_lst[0], "echo"))
			result = echo(cmd_lst, fd);
		else if (!ft_strcmp(cmd_lst[0], "cd"))
			result = cd(cmd_lst, get_adress_envp());
		else if (!ft_strcmp(cmd_lst[0], "pwd"))
			result = pwd(fd);
		else if (ft_strcmp(cmd_lst[0], "env") == 0)
			result = env(*get_adress_envp(), fd);
		else if (ft_strcmp(cmd_lst[0], "export") == 0)
			result = export(cmd_lst, get_adress_envp(), fd);
		else
			result = unset(cmd_lst);
	}
	return (result);
}
