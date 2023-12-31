/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:51:11 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/28 15:51:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	init_type(t_token *new)
{
	int	len;

	len = 0;
	if (new->str)
		len = ft_strlen(new->str);
	if (len == 1)
	{
		if (new->str[0] == '<')
			new->type = INPUT;
		else if (new->str[0] == '>')
			new->type = TRUNC;
	}
	if (len == 2)
	{
		if (new->str[0] == '<' && new->str[1] == '<')
			new->type = HEREDOC;
		if (new->str[0] == '>' && new->str[1] == '>')
			new->type = APPEND;
	}
	if (is_builtin(new->str))
		new->type = BUILTIN;
	if (new->type == NON && len != 0)
		new->type = ARG;
}
