
#include "../../../headers/minishell.h"

int    break_simple_cmds(char *line, t_cmd_line **simple_cmd_list)
{
    int	idx;
	int	cmd_start;

	idx = 0;
	cmd_start = 0;
	while (line[idx])
	{
		if (idx != 0)
		{
			idx++;
			cmd_start++;
		}
		strlen_simple_cmd(line, &idx);
		add_cmd_to_list(line, idx, cmd_start, simple_cmd_list);
		cmd_start = idx;
		if (idx == 0)
		{
			idx++;
			cmd_start++;
		}
	}
	return (0);
}