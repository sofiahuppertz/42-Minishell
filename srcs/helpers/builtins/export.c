/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 22:22:28 by sofia            ###   ########.fr       */
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

static void	print_env(t_env *env, int fd)
{
	char	**sorted_env;
	int		var;

	var = 0;
	sorted_env = envp_sort(env);
	while (sorted_env[var])
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putendl_fd(sorted_env[var], fd);
		var++;
	}
	ft_memdel_2d((void **)sorted_env);
}

int	export(const char **args, t_env **env, int fd)
{
	int		status;
	int 	idx;
	int		value_in_env;
	char	*name;
	char	*value;



	status = 0;
	name = NULL;
	value = NULL;
	if (!args[1])
		print_env(*env, fd);
	else
	{
		idx = 1;
		while (args[idx])
		{
			status = envp_is_valid_varname(args[idx]);
			if (status <= 0)
			{
				status = print_error(status, (const char *)args[idx]);
				idx += 1;
				continue;
			}
			name = envp_get_var(args[idx]);
			value_in_env = envp_is_value_in_env(name);
			if (name && value_in_env)
			{
				value = get_value(args[idx], status);
				status = envp_modify_var((const char *)value, (const char *)name,
						env);
				ft_memdel(value);
			}
			else if (name)
			{
				if (status == 3)
				{
					value = ft_strjoin(args[idx], "\"\"");
					status = envp_add_var((const char *)value, env);
					ft_memdel(value);
				}
				else
					status = envp_add_var((const char *)args[idx], env);
			}
			ft_memdel(name);
			idx += 1;
		}
	}
	return (status);
}
