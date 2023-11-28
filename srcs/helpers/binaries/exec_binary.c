/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:03 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 12:53:46 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static char	*search_path_for_command(char **dirs, char *command)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (dirs[i])
	{
		temp = ft_strjoin(dirs[i], "/");
		path = ft_strjoin(temp, command);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		else if (errno != ENOENT)
		{
			free(path);
			return (NULL);
		}
		free(path);
		i++;
	}
	return (NULL);
}

int	exec_binary(char **args, t_cmd_line **cmd_line)
{
	char *path;
	char **dirs;

	dirs = ft_split(getenv("PATH"), ':');
	if (access(args[0], X_OK) == 0)
	{
		ft_execve(args[0], args, dirs, cmd_line);
	}
	else
	{
		path = search_path_for_command(dirs, args[0]);
		if (path != NULL)
		{
			delete_cmd_line_except_argv(cmd_line);
			ft_execve(path, args, dirs);
		}
		else
		{
			delete_cmd_line(cmd_line);
			delete_envp();
			ft_memdel_2d((void **)dirs);
			access_failure(args[0]);
		}
	}
	return (0);
}