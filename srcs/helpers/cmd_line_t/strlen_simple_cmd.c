/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_simple_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:46 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 19:00:45 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	strlen_simple_cmd(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '|' && !find_open_quotes(str, *i))
			return ;
		(*i)++;
	}
	return ;
}
