/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:37 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:48:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	cmd_count(t_cmd_line *cmd_line)
{
	int	len;

	len = 0;
	while (cmd_line)
	{
		len++;
		cmd_line = cmd_line->next;
	}
	return (len);
}
