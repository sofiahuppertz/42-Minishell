
#include "../../../headers/minishell.h"

int		is_delim(char *line, int i)
{
	if (ft_strchr("<>|", line[i]) && !find_open_quotes(line, i))
		return (1);
	else
		return (0);
}
