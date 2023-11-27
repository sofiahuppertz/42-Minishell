/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:02:02 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/10 16:58:57 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static t_list	*new_list(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	list_clear(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*headref;

	if (!lst || !f || !del)
		return (NULL);
	new = new_list(f(lst->content));
	if (!new)
	{
		return (NULL);
	}
	headref = new;
	lst = lst->next;
	while (lst)
	{
		new->next = new_list(f(lst->content));
		if (!new->next)
		{
			list_clear(&headref, del);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (headref);
}
