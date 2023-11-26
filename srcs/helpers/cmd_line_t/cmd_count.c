
#include "../../../headers/minishell.h"

int cmd_count(t_cmd_line *cmd_line)
{
    int	len;

	len = 0;
	while (cmd_line)
	{
		len++;
		cmd_line = cmd_line->next;
	}
	return (len);
}
