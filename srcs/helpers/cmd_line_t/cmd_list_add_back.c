/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:42 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 19:00:42 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	cmd_list_add_back(t_cmd_line **head, t_cmd_line *last)
{
	t_cmd_line	*cur;

	cur = *head;
	if (cur == NULL)
		*head = last;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = last;
	}
}
