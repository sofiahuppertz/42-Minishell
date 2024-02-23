/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:50:15 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:09:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubble_sort_envp(char **sorted_envp, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(sorted_envp[j], sorted_envp[j + 1]) > 0)
				swap(&sorted_envp[j], &sorted_envp[j + 1]);
			j += 1;
		}
		i += 1;
	}
}

char	**envp_sort(t_env *env)
{
	int		count;
	char	**sorted_envp;
	int		i;

	count = envp_count(env) + 1;
	sorted_envp = ft_calloc(sizeof(char *), count + 1);
	if (!sorted_envp)
		return (NULL);
	i = 0;
	while (env && i < count)
	{
		sorted_envp[i] = ft_strdup(env->str);
		env = env->next;
		i += 1;
	}
	sorted_envp[count] = NULL;
	bubble_sort_envp(sorted_envp, count);
	return (sorted_envp);
}
