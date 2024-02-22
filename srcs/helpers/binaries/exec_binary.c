/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:03 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/22 19:45:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static char *search_path_for_command(char *command)
{
	char **paths;
	char *path;
	char *temp;
	int i;

	i = -1;
	temp = e_get_val("PATH", *get_adress_envp());
	if (!temp)
		return (NULL);
	paths = ft_split(temp, ':');
	ft_memdel((void *)temp);
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, command);
		free(temp);
		if (access(path, X_OK) == 0)
			break;
		free(path);
		path = NULL;
		if (errno != ENOENT)
			break;
	}
	ft_memdel_2d((void **)paths);
	return (path);
}

static void handle_command_not_found(char **args,
									 t_cmd_line ***cmd_line)
{
	char *command;

	command = NULL;
	if (args[0])
		command = ft_strdup(args[0]);
	delete_envp();
	delete_char_envp();
	delete_cmd_line(*cmd_line);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	access_failure(command);
}

int exec_binary(char **args, t_cmd_line **cmd_line)
{
	char *path;
	char **env;

	env = *get_adress_char_envp();
	if (!args[0])
		handle_command_not_found(args, &cmd_line);
	else if (access(args[0], X_OK) == 0)
	{
		delete_envp();
		dlt_cmdline_but_argv(cmd_line);
		ft_execve(args[0], args, env);
	}
	else
	{
		path = search_path_for_command(args[0]);
		if (path != NULL)
		{
			ft_execve(path, args, env);
		}
		else
			handle_command_not_found(args, &cmd_line);
	}
	return (0);
}
