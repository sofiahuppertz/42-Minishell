/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:54:37 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/07 19:30:30 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	init_signals(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	return (1);
}
