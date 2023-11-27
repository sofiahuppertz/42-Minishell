
#include "../../headers/minishell.h"

int	dispatcher(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int				idx;
	t_cmd_line	*simple_cmd;

	idx = 0;
	simple_cmd = *cmd_line;
	while (simple_cmd)
	{
		redir(&simple_cmd);
		simple_cmd = simple_cmd->next;
	}
	if (!g_sig.stop_exec)
	{
		simple_cmd = *cmd_line;
		if (num_cmds == 1 && is_builtin(simple_cmd->argv[0]))
			g_sig.status = exec_builtin((const char **)(*cmd_line)->argv, (*cmd_line)->fd_out);
		else
		{
			while (idx < num_cmds)
			{
				fork_and_exec(pid, idx, cmd_line, &simple_cmd);
				simple_cmd = simple_cmd->next;
				idx++;
			}
		}
	}
	return (0);
}