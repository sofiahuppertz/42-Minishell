/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 21:29:18 by sofia            ###   ########.fr       */
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

static int	cd_home(t_env **env)
{
	char	*home_path;
	int		exit_status;
	char	curr_dir[PATH_MAX + 1];

	home_path = e_get_val("HOME", *env);
	if (!home_path)
	{
		ft_putendl_fd("minishell : cd: HOME not set", STDERR);
		return (ERROR);
	}
	exit_status = chdir(home_path);
	getcwd(curr_dir, PATH_MAX);
	envp_update_pwd(curr_dir);
	free(home_path);
	return (exit_status);
}

static int	cd_prev_dir(t_env **env)
{
	char	*prev_path;
	int		exit_status;
	char	curr_dir[PATH_MAX + 1];

	prev_path = e_get_val("OLDPWD", *env);
	if (!prev_path)
	{
		ft_putendl_fd("minishell : cd: OLDPWD not set", STDERR);
		return (ERROR);
	}
	exit_status = chdir(prev_path);
	getcwd(curr_dir, PATH_MAX);
	envp_update_pwd(curr_dir);
	free(prev_path);
	return (exit_status);
}

int	cd(const char **args, t_env **env)
{
	int		exit_status;
	char	curr_dir[PATH_MAX + 1];

	if (!args[1])
		exit_status = cd_home(env);
	else if (ft_strcmp(args[1], "-") == 0)
		exit_status = cd_prev_dir(env);
	else
	{
		exit_status = chdir(args[1]);
		getcwd(curr_dir, PATH_MAX);
		envp_update_pwd(curr_dir);
		if (exit_status != 0)
		{
			print_error(args);
			exit_status = 1;
		}
	}
	return (exit_status);
}
