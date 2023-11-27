/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:15 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 19:03:03 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	print_error(const char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd((char *)args[1], 2);
}

static int	update_old_dir(t_env **env)
{
	char	current_dir[PATH_MAX + 1];
	char	*old_pwd;

	if (!(getcwd(current_dir, PATH_MAX)))
		return (ERROR);
	old_pwd = envp_get_value((const char *)"PWD", *env);
	if (!old_pwd)
	{
		old_pwd = ft_strjoin((const char *)"OLDPWD=",
								(const char *)current_dir);
		if (!old_pwd)
			return (ERROR);
		if (envp_add_var((const char *)old_pwd, env) == ERROR)
			exit_failure();
	}
	else
	{
		if (envp_modify_var((const char *)"OLDPWD", (const char *)current_dir,
				env) == ERROR)
			exit_failure();
	}
	free(old_pwd);
	return (SUCCESS);
}

static int	cd_home(t_env **env)
{
	char	*home_path;
	int		exit_status;

	update_old_dir(env);
	home_path = envp_get_value("HOME", *env);
	if (!home_path)
	{
		ft_putendl_fd("minishell : cd: HOME not set", STDERR);
		return (ERROR);
	}
	exit_status = chdir(home_path);
	free(home_path);
	return (exit_status);
}

static int	cd_prev_dir(t_env **env)
{
	char	*prev_path;
	int		exit_status;

	prev_path = envp_get_value("OLDPWD", *env);
	if (!prev_path)
	{
		ft_putendl_fd("minishell : cd: OLDPWD not set", STDERR);
		return (ERROR);
	}
	update_old_dir(env);
	exit_status = chdir(prev_path);
	free(prev_path);
	return (exit_status);
}

int	cd(const char **args, t_env **env)
{
	int	exit_status;

	if (!args[1])
		exit_status = cd_home(env);
	else if (ft_strcmp(args[1], "-") == 0)
		exit_status = cd_prev_dir(env);
	else
	{
		update_old_dir(env);
		exit_status = chdir(args[1]);
		if (exit_status != 0)
		{
			print_error(args);
			if (exit_status < 0)
				exit_status *= -1;
		}
	}
	return (exit_status);
}
