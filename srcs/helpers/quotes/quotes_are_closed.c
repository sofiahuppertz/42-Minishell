
#include "../../../headers/minishell.h"

int		quotes_are_closed(char *line)
{
	if (find_open_quotes(line, 4095))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", 2);
		return (0);
	}
	return (1);
}