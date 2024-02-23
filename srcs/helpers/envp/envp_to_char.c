/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:44 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:09:02 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	envp_to_char(void)
{
	t_env	*shallow_env;
	char	***char_envp;
	char	**temp;
	int		count;
	int		idx;

	shallow_env = *get_adress_envp();
	count = envp_count(shallow_env);
	delete_char_envp();
	temp = ft_calloc(sizeof(char *), count + 1);
	idx = 0;
	while (shallow_env && idx < count)
	{
		temp[idx] = ft_strdup(shallow_env->str);
		shallow_env = shallow_env->next;
		idx += 1;
	}
	temp[count] = NULL;
	char_envp = get_adress_char_envp();
	*char_envp = temp;
	return ;
}
