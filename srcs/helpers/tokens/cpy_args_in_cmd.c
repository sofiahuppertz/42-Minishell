
#include "../../../headers/minishell.h"

void	cpy_args_in_cmd(t_cmd_line *simple_cmd)
{
	t_token	*token;
	int		i;

	token = simple_cmd->first_token;
	i = 0;
	while (token)
	{
		if (token->type == ARG || token->type == BUILTIN)
		{
			simple_cmd->argv[i] = token->str;
			i++;
		}
		token = token->next;
	}
	simple_cmd->argv[i] = NULL;
}
