/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 12:48:46 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	ft_execve(char *path, char **args, char **dirs)
{
	if (execve(path, args, dirs) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		ft_memdel_2d((void **)dirs);
		ft_memdel_2d((void **)args);
		ft_memdel((void *)path);
		delete_envp();
		exit(ERROR);
	}
	return (ERROR);
}
