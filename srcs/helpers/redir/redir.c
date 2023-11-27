
#include "../../../headers/minishell.h"

int	redir(t_cmd_line **simple_cmd)
{
	t_token	*token;

	token = (*simple_cmd)->first_token;
	while (token)
	{
		if (token->type == FILE_IN)
            redirect_stdin(simple_cmd, token);
        else if (token->type == LIMIT)
            redirect_heredoc(simple_cmd, token);
        else if(token->type == FILE_TRUNC)
            redirect_stdout(simple_cmd, token, O_TRUNC);
        else if(token->type == FILE_APPEND)
            redirect_stdout(simple_cmd, token, O_APPEND);
		token = token->next;
	}
	return (0);
}
