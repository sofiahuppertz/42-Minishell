
#include "../../../headers/minishell.h"

int	tokenize(t_cmd_line **head)
{
	t_cmd_line	*simple_cmd;

	simple_cmd = *head;
	while (simple_cmd)
	{
		string_to_tokens(&simple_cmd);
		simple_cmd = simple_cmd->next;
	}
	return (0);
}
