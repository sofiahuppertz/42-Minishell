/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:30 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:52:34 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	delete_envp(void)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *get_adress_envp();
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		ft_memdel(tmp->str);
		ft_memdel(tmp);
	}
	return ;
}
