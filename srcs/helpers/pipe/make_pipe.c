
#include "../../../headers/minishell.h"

int	make_pipe(int **fds, int idx, t_cmd_line *simple_cmd)
{
	fds[idx] = ft_calloc(sizeof(int), 2);
	if (fds[idx] == NULL)
		exit_failure();
	if (pipe(fds[idx]) == -1)
		return (1);
	if (idx == 0)
		cmd->fd_in = 0;
	else
		cmd->fd_in = fds[idx - 1][0];
	if (cmd->next == NULL)
	{
		close(fds[idx][0]);
		close(fds[idx][1]);
		cmd->fd_out = 1;
	}
	else
		cmd->fd_out = fds[idx][1];
	return (0);
}