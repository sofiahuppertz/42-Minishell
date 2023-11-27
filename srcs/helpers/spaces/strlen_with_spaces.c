/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_with_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:07 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:55:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	strlen_with_spaces(char *str)
{
	int	new_str_len;
	int	index;

	new_str_len = 0;
	index = 0;
	while (str[index])
	{
		if (is_delim(str, index))
			new_str_len += 2;
		new_str_len++;
		index++;
	}
	new_str_len += 1;
	return (new_str_len);
}
