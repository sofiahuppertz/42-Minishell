/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:31:59 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/09 21:11:30 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*node;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			node = *lst;
			while (node->next)
				node = node->next;
			node->next = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}
