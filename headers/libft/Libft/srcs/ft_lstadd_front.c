/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:04:37 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/09 13:31:17 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstadd_front(t_list **frontlst, t_list *new_lst)
{
	if (*frontlst != NULL)
	{
		new_lst->next = *frontlst;
		*frontlst = new_lst;
	}
	else
		*frontlst = new_lst;
}
