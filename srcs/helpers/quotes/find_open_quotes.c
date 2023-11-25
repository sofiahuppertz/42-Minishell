#include "../../../headers/minishell.h"

int		find_open_quotes(char *line, int max_index)
{
	int	index;
	int	quote;

	index = 0;
	quote = 0;
	
	while (line[index] && index != max_index)
	{
		if (quote == 0 && line[index] == '\"')
			quote = 1;
		else if (quote == 0 && line[index] == '\'')
			quote = 2;
		else if (quote == 1 && line[index] == '\"')
			quote = 0;
		else if (quote == 2 && line[index] == '\'')
			quote = 0;
		index++;
	}
	return (quote);
}