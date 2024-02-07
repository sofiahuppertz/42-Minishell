/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:42:26 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 11:39:58 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	is_empty_line(char *str)
{
	int	index;

	index = 0;
	index = ft_add_while_true(index, str, &ft_iswhitespace);
	if (str[index] == '\0')
		return (1);
	return (0);
}
