/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_failure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:47:00 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	access_failure(char *command)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(command, STDERR);
	if (errno == ENOENT)
		ft_putendl_fd(": command not found", STDERR);
	else if (errno == EACCES)
		ft_putendl_fd(": Permission denied", STDERR);
	else if (errno == EISDIR)
		ft_putendl_fd(": is a directory", STDERR);
	else if (errno == ENOTDIR)
		ft_putendl_fd(": No such file or directory", STDERR);
	if (errno == ENOENT || errno == ENOTDIR)
		return (127);
	else if (errno == EACCES || errno == EISDIR)
		return (126);
	else
		return (1);
}
