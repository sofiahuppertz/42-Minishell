/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:53:43 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/27 18:53:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

void	organize_redirections(t_cmd_line **full_cmd)
{
	set_heredoc_limit(full_cmd);
	set_file_types(full_cmd);
	return ;
}
