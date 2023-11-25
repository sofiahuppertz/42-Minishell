
#include "../../../headers/minishell.h"

void	cmd_list_add_back(t_cmd_line **head, t_cmd_line *last)
{
	t_cmd_line	*cur;

	cur = *head;
	if (cur == NULL)
		*head = last;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = last;
	}
}