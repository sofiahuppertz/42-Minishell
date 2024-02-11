/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:30 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/11 14:32:21 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	return_error(char c)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (c == '<')
		ft_putstr_fd("newline", 2);
	else
		ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
	return (1);
}

static int	count_previous_redir(char *str, int i)
{
	int	count;

	count = 0;
	while (i >= 0)
	{
		if (str[i] == '>' || str[i] == '<')
			count++;
		if (ft_iswhitespace(str[i]) == 0 && str[i] != '>' && str[i] != '<')
			break ;
		i--;
	}
	return (count);
}

int	invalid_redirections(char *str)
{
	int		i;
	char	last_redirect;

	i = 0;
	last_redirect = '\0';
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			if ((last_redirect != '\0' && last_redirect != str[i])
				|| count_previous_redir(str, i) > 2)
			{
				if (!find_open_quotes(str, i))
					return (return_error(str[i]));
			}
			last_redirect = str[i];
		}
		else if (str[i] != ' ')
			last_redirect = '\0';
		i++;
	}
	if (last_redirect != '\0')
		return (return_error(last_redirect));
	return (0);
}
