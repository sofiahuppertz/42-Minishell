/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_expanded_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:12 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:23:14 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int extract_var_and_len(const char *arg, int *idx, t_env *env)
{
	char varname[1025];
	char *buffer;
	int len = 0;

	while (len < 1024 && arg[*idx] && (ft_isalnum(arg[*idx]) || arg[*idx] == '_'))
		varname[len++] = arg[(*idx)++];
	varname[len] = '\0';
	buffer = envp_get_value((const char *)varname, env);
	if (!buffer)
		len = 0;
	else
		len = ft_strlen(buffer);
	ft_memdel(buffer);
	return len;
}

int strlen_expanded_var(const char *arg, int idx, t_env *env)
{
	char *buffer;
	int len = 0;

	buffer = NULL;
	if (arg[idx] == '?')
	{
		buffer = ft_itoa(g_sig.status);
		len = ft_strlen(buffer);
	}
	else if (ft_isdigit(arg[idx]))
	{
		return 0;
	}
	else
	{
		len = extract_var_and_len(arg, &idx, env);
	}
	ft_memdel(buffer);
	return len;
}
