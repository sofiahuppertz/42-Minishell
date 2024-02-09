/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_failure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:57 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/09 17:59:12 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	print_error_type(void)
{
	if (errno == ENOENT || errno == ENOTDIR)
		ft_putendl_fd(": command not found", STDERR);
	else if (errno == EACCES)
		ft_putendl_fd(": Permission denied", STDERR);
	else if (errno == EISDIR)
		ft_putendl_fd(": is a directory", STDERR);
	return ;
}

void	access_failure(char *command)
{
	ft_putstr_fd("minishell: ", STDERR);
	if (!command)
	{
		ft_putendl_fd(": command not found", STDERR);
		*status_pointer() = 127;
	}
	else
	{
		ft_putstr_fd(command, STDERR);
		print_error_type();
		if (errno == ENOENT || errno == ENOTDIR)
			*status_pointer() = 127;
		else if (errno == EACCES || errno == EISDIR)
			*status_pointer() = 126;
		else
			*status_pointer() = 1;
		free(command);
	}
	exit(*status_pointer());
}
