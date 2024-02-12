/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:27 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 13:50:28 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	add_cmd_to_list(char *str, int cur, int start, t_cmd_line **head)
{
	t_cmd_line	*new;

	new = ft_calloc(sizeof(t_cmd_line), 1);
	if (new == NULL)
		return (exit_failure());
	new->string = ft_calloc(sizeof(char), (cur - start + 1));
	if (new->string == NULL)
		return (exit_failure());
	new->string = ft_strncpy(new->string, str + start, cur - start);
	cmdl_add(head, new);
	return ;
}
