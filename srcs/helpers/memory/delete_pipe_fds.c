/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipe_fds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:52:35 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:52:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	delete_pipe_fds(int **fds)
{
	int	i;

	i = 0;
	while (fds[i])
	{
		free(fds[i]);
		i++;
	}
	free(fds);
}
