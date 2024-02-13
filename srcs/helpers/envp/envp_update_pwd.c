/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_update_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:23:25 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/13 21:50:40 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	update_oldpwd(char *temp_val, t_env ***env)
{
	char	*temp;
	int		yes;

	if (!temp_val)
		return ;
	yes = envp_is_value_in_env("OLDPWD");
	if (yes)
		e_modify_var(temp_val, "OLDPWD=", *env);
	else
	{
		temp = ft_strjoin("OLDPWD=", temp_val);
		envp_add_var(temp, *env);
		ft_memdel((void *)temp);
	}
}

void	envp_update_pwd(char *curr_dir, char *old_dir)
{
	char	*temp;
	int		yes;
	t_env	**env;

	env = get_adress_envp();
	update_oldpwd(old_dir, &env);
	yes = envp_is_value_in_env("PWD");
	if (yes)
		e_modify_var(curr_dir, "PWD=", env);
	else
	{
		temp = ft_strjoin("PWD=", curr_dir);

		envp_add_var(temp, env);

		free(temp);
	}
	return ;
}
