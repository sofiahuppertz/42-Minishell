/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:27 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 19:00:25 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	add_cmd_to_list(char *str, int cur, int start, t_cmd_line **head)
{
	t_cmd_line	*new;

	new = ft_calloc(sizeof(t_cmd_line), 1);
	if (new == NULL)
		return (exit_failure());
	new->string = malloc(sizeof(char) * (cur - start + 1));
	if (new->string == NULL)
		return (exit_failure());
	new->string = ft_strncpy(new->string, str + start, cur - start);
	cmd_list_add_back(head, new);
	return ;
}
