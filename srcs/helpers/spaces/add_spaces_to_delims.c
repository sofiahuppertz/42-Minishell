/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces_to_delims.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:55 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 22:05:45 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	add_spaces_to_delims(char **str)
{
	int		new_len;
	char	*new_str;

	new_len = strlen_with_spaces(*str);
	new_str = ft_calloc(sizeof(char), new_len);
	if (!new_str)
	{
		free(*str);
		return (0);
	}
	strcpy_adding_spaces(&new_str, *str);
	ft_memdel((void *)*str);
	*str = new_str;
	return (1);
}
