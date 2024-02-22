/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:50:19 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/22 18:55:30 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void delete_char_envp(void)
{
	char **temp;

	temp = *get_adress_char_envp();
	if (temp != NULL)
	{
		ft_memdel_2d((void **)temp);
	}
	return;
}