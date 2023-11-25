
#include "../../../headers/minishell.h"

void	strlen_simple_cmd(char *str, int *i)
{

	while (str[*i])
	{
		if (str[*i] == '|' && !find_open_quotes(str, *i))
			return ;
		(*i)++;
	}
	return ;
}