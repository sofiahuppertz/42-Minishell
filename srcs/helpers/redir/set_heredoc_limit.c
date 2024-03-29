/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc_limit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:28 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/23 18:11:25 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	set_heredoc_limit(t_cmd_line **full_cmd)
{
	t_cmd_line	*cur_b;
	t_token		*cur_t;
	int			limit;
	int			idx;

	cur_b = *full_cmd;
	limit = 0;
	while (cur_b)
	{
		cur_t = cur_b->first_token;
		while (cur_t)
		{
			if (cur_t->type == HEREDOC)
				limit = 1;
			else if (limit == 1 && cur_t->str && cur_t->str[0] != '\0')
			{
				cur_t->type = LIMIT;
				idx = 0;
				while (cur_t->str[idx])
				{
					if (cur_t->str[idx] == -36)
						cur_t->str[idx] = 36;
					idx++;
				}
				limit = 0;
			}
			cur_t = cur_t->next;
		}
		cur_b = cur_b->next;
	}
	return (0);
}
