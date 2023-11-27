/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:27:36 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/10 16:58:10 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	node = *lst;
	if (lst)
	{
		while (node != NULL)
		{
			*lst = node->next;
			if (node != NULL && node->content != NULL)
			{
				(del)(node->content);
				free(node);
				node = NULL;
			}
			node = *lst;
		}
	}
}
