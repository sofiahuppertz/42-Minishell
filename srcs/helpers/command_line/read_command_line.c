/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:48:53 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/09 17:11:23 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	read_command_line(char **line)
{
	if (line == NULL)
		return ;	
	*line = readline("minishell ▸ ");
	if (*line == NULL)
	{
		ft_putstr_fd("\b\b", 1);
		ft_putendl_fd("exit 👋", 1);
		*exit_shell() = 1;
	}
	if ((*line) && (*line)[0] != '\0')
	{
		add_history(*line);
		signal(SIGQUIT, sigquit_handler);
	}
		
	return ;
}
