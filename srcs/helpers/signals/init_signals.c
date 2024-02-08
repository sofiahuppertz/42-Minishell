/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:37 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/08 11:59:34 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	init_signals(void)
{
	caught_signal = 0;
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (1);
}
