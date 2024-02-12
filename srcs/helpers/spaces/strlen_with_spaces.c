/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_with_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:07 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/12 22:05:44 by sofia            ###   ########.fr       */
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
		else if (str[index] == '$' && str[index + 1] == '\'')
			new_str_len -= 1;
		new_str_len++;
		index++;
	}
	new_str_len += 1;
	return (new_str_len);
}
