/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_delim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:37 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:53:40 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	is_delim(char *line, int i)
{
	if (ft_strchr("<>|", line[i]) && !find_open_quotes(line, i))
		return (1);
	else
		return (0);
}
