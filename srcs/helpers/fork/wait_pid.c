
#include "../../../headers/minishell.h"

int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds)
{
	int				idx;

	idx = 0;
	if (num_cmds == 1 && is_builtin((*cmd_line)->argv[0]))
	{
		return (0);
	}
	while (idx < num_cmds)
	{
		waitpid(pid[idx], &g_sig.status, 0);
		if (WIFEXITED(g_sig.status))
			g_sig.status = WEXITSTATUS(g_sig.status);
		else if (WIFSIGNALED(g_sig.status))
			g_sig.status = 128 + WTERMSIG(g_sig.status);
		idx++;
	}
	return (0);
}
