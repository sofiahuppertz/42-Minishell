/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:05 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:58:21 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	pwd(int fd)
{
	char	curr_dir[PATH_MAX];

	if (getcwd(curr_dir, PATH_MAX))
	{
		ft_putendl_fd(curr_dir, fd);
		return (SUCCESS);
	}
	else
		return (ERROR);
}
