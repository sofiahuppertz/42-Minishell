/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:56:21 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:56:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	syntax_ok(char *str)
{
	if (!quotes_are_closed(str))
		return (0);
	if (duplicate_pipes(str))
		return (0);
	if (invalid_redirections(str))
		return (0);
	return (1);
}
