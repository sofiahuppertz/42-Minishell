/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:28 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 11:51:46 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

t_token	*create_node(int str_len)
{
	t_token	*new_token;

	new_token = ft_calloc(sizeof(t_token), 1);
	if (!new_token)
		return (NULL);
	//if str_len = 1 ?
	new_token->str = ft_calloc(sizeof(char), str_len);
	if (!new_token->str)
	{
		free(new_token);
		return (NULL);
	}
	new_token->expanded = 0;
	new_token->type = NON;
	return (new_token);
}
