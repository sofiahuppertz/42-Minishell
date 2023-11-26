
#include "../../../headers/minishell.h"

int	token_list_to_array(t_cmd_line **cmds)
{
	t_cmd_line	*simple_cmd;
	int				cmd_count;
	char			**new;

	simple_cmd = *cmds;
	while (simple_cmd)
	{
		count_args_in_cmd(simple_cmd, &cmd_count);
		new = malloc(sizeof(char *) * (cmd_count + 1));
		if (!new)
			exit_failure();
		simple_cmd->argv = new;
		cpy_args_in_cmd(simple_cmd);
		simple_cmd = simple_cmd->next;
	}
	return (0);
}