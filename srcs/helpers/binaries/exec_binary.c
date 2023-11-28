/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:03 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:41:06 by shuppert         ###   ########.fr       */
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

static void	handle_command_not_found(char **dirs, char **args,
		t_cmd_line ***cmd_line)
{
	char	*command;

	command = ft_strdup(args[0]);
	delete_cmd_line(*cmd_line);
	ft_memdel_2d((void **)dirs);
	access_failure(command);
}

int	exec_binary(char **args, t_cmd_line **cmd_line)
{
	char	*path;
	char	**dirs;

	delete_envp();
	dirs = ft_split(getenv("PATH"), ':');
	if (access(args[0], X_OK) == 0)
	{
		ft_execve(args[0], args, dirs);
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
			handle_command_not_found(dirs, args, &cmd_line);
		}
	}
	return (0);
}
