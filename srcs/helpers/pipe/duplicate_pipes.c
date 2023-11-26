
#include "../../../headers/minishell.h"

static int print_pipe_error(void)
{
	ft_putstr_fd("minishell: syntax error near: unexpected token `|'\n", 2);
	g_sig.status = 258;
	return (1);
}

int duplicate_pipes(char *str)
{

	int	idx;
	int	pipe;

	idx = 0;
	pipe = 0;
	while (str[idx])
	{
		if (str[idx] != ' ' && str[idx] != '|')
			pipe = 1;
		if (str[idx] == '|')
		{
			if (pipe == 0 && !find_open_quotes(str, idx))
				return (print_pipe_error());
			pipe = 0;
		}
		idx++;
	}
	while (idx >= 0 && ft_iswhitespace(str[idx]))
        idx--;
    if (str[idx] == '|')
		return (print_pipe_error());
	return (0);
}