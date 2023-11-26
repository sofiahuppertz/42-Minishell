
#include "../../../headers/minishell.h"


static t_type  file_type(t_type delim, int *file)
{
	*file = 0;
	if (delim == INPUT)
		return (FILE_IN);
	else if (delim == TRUNC)
		return (FILE_TRUNC);
	else if (delim == APPEND)
		return (FILE_APPEND);
	else if (delim == HEREDOC)
		return (LIMIT);
	return (NON);
}

int	set_file_types(t_cmd_line **full_cmd)
{
    int				prev_delim;
	t_cmd_line	*simple_cmd;
	t_token			*token;
	t_type		delim;

	simple_cmd = *full_cmd;
	prev_delim = 0;
	while (simple_cmd)
	{
		token = simple_cmd->first_token;
		while (token)
		{
			if (token->type == INPUT || token->type == TRUNC 
				|| token->type == APPEND || token->type == HEREDOC)
            {
                prev_delim = 1;
                delim = token->type;
            }
			else if (prev_delim == 1 && token->str && (token->str[0] != '\0'))
				token->type = file_type(delim, &prev_delim);
			token = token->next;
		}
		simple_cmd = simple_cmd->next;
	}
	return (0);
}