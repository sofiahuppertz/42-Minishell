/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_failure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:57 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 16:56:55 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	print_error_type(void)
{
	if (errno == EACCES)
		ft_putendl_fd(": Permission denied", STDERR);
	else if (errno == EISDIR)
		ft_putendl_fd(": is a directory", STDERR);
	else
		ft_putendl_fd(": command not found", STDERR);
	return ;
}

void	access_failure(char *command)
{
	if (command)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(command, STDERR);
		print_error_type();
		if (errno == EACCES || errno == EISDIR)
			*status_pointer() = 126;
		else
			*status_pointer() = 127;
		free(command);
	}
	exit(*status_pointer());
}
