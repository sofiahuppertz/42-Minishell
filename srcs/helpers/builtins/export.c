/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:52 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 21:48:39 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	print_error(int status, const char *arg)
{
	int	i;

	if (status == -1)
		ft_putstr_fd("export: not valid in this context: ", 2);
	else if (status == 0 || status == -3)
		ft_putstr_fd("export: not a valid identifier: ", 2);
	i = 0;
	while (arg[i] && (arg[i] != '=' || status == -3))
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return (1);
}

static char	*get_value(const char *arg, int status)
{
	char	*value;
	int		i;
	int		len;

	i = 0;
	if (status == 1)
	{
		while (arg[i] != '=')
			i++;
		len = ft_strlen(arg) - i;
		value = ft_substr(arg, i + 1, len);
	}
	else if (status == 2)
		value = ft_strdup("");
	else
		value = ft_strdup("\"\"");
	return (value);
}

static int	handle_add_new_vars(const char *arg, int status, t_env **env)
{
	char	*value;

	if (status == 3)
	{
		value = ft_strjoin(arg, "\"\"");
		status = envp_add_var(value, env);
		ft_memdel(value);
	}
	else
		status = envp_add_var(arg, env);
	return (status);
}

static int	handle_arg(const char *arg, t_env **env, int status)
{
	int		value_in_env;
	char	*name;
	char	*value;

	name = envp_get_var(arg);
	value_in_env = envp_is_value_in_env(name);
	if (name && value_in_env)
	{
		value = get_value(arg, status);
		status = e_modify_var(value, name, env);
		ft_memdel(value);
	}
	else if (name)
		status = handle_add_new_vars(arg, status, env);
	ft_memdel(name);
	return (status);
}

int	export(const char **args, t_env **env, int fd)
{
	int	status;
	int	idx;

	if (!args[1])
	{
		envp_print_sorted_env(*env, fd);
		return (0);
	}
	idx = 1;
	while (args[idx])
	{
		status = envp_is_valid_varname(args[idx]);
		if (status <= 0)
		{
			print_error(status, args[idx]);
			idx += 1;
			continue ;
		}
		status = handle_arg(args[idx], env, status);
		idx += 1;
	}
	return (status);
}
