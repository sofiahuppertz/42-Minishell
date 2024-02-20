/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_adding_spaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:01 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/20 10:16:33 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	process_char(char **new_str, char *str, int *idx)
{
	if (str[*idx] == '$' && str[*idx + 1] == '\'')
		(*idx)++;
	else if (find_open_quotes(str, *idx) != 2 && str[*idx] == '$' && str[*idx
			+ 1] != '\"')
		*(*new_str)++ = (char)(-str[(*idx)++]);
	else if (!find_open_quotes(str, *idx) && is_delim(str, *idx))
	{
		*(*new_str)++ = ' ';
		*(*new_str)++ = str[(*idx)++];
		if (find_open_quotes(str, *idx) == 0 && (str[*idx] == '>'
				|| str[*idx] == '<'))
			*(*new_str)++ = str[(*idx)++];
		*(*new_str)++ = ' ';
	}
	else
		*(*new_str)++ = str[(*idx)++];
}

void	strcpy_adding_spaces(char **new, char *str)
{
	char	*new_str;
	int		idx;

	if (!new || !(*new) || !str)
		return ;
	idx = 0;
	new_str = *new;
	while (str[idx])
	{
		process_char(&new_str, str, &idx);
	}
	*new_str = '\0';
}
