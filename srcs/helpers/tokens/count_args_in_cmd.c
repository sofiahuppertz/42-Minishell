
#include "../../../headers/minishell.h"

void	count_args_in_cmd(t_cmd_line *simple_cmd, int *len)
{
	t_token	*token;

	*len = 0;
	token = simple_cmd->first_token;
	while (token)
	{
		if (token->type == ARG || token->type == BUILTIN)
			*len += 1;
		token = token->next;
	}
	return;
}
