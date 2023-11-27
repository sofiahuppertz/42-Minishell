/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_are_closed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:23 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:53:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	quotes_are_closed(char *line)
{
	if (find_open_quotes(line, 4095))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", 2);
		return (0);
	}
	return (1);
}
