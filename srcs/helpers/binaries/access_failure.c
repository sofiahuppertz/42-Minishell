/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_failure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 12:22:38 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	print_error_type(void)
{
	if (errno == ENOENT)
		ft_putendl_fd(": command not found", STDERR);
	else if (errno == EACCES)
		ft_putendl_fd(": Permission denied", STDERR);
	else if (errno == EISDIR)
		ft_putendl_fd(": is a directory", STDERR);
	else if (errno == ENOTDIR)
		ft_putendl_fd(": No such file or directory", STDERR);
	return ;
}

void	access_failure(char *command)
{
	int	status;

	status = 0;
	ft_putstr_fd("minishell: ", STDERR);
	if (!command)
		ft_putendl_fd(": command not found", STDERR);
	else
	{
		ft_putstr_fd(command, STDERR);
		print_error_type();
		if (errno == ENOENT || errno == ENOTDIR)
			status = 127;
		else if (errno == EACCES || errno == EISDIR)
			status = 126;
		else
			status = 1;
		free(command);
	}
	exit(status);
}
