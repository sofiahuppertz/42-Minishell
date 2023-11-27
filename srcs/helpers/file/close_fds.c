
#include "../../../headers/minishell.h"

void	close_fds(t_cmd_line **cmd_line)
{
	t_cmd_line	*simple_cmd;

	simple_cmd = *cmd_line;
	while (simple_cmd)
	{
		if (simple_cmd->fd_in != 0)
			close(simple_cmd->fd_in);
		if (simple_cmd->fd_out != 1)
			close(simple_cmd->fd_out);
		simple_cmd = simple_cmd->next;
	}
}