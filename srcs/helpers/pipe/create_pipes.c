
#include "../../../headers/minishell.h"

int	create_pipes(t_cmd_line **cmd_line)
{
	t_cmd_line	*simple_cmd;
	int				**fds;
	int				file_idx;
    int            num_cmds;


	simple_cmd = *cmd_line;
    num_cmds = cmd_count(simple_cmd);
	fds = ft_calloc(sizeof(int *), num_cmds + 1);
	if (fds == NULL)
        exit_failure(); //replace for a function that frees everything	
	fds[num_cmds] = NULL;
    file_idx = 0;
	while (simple_cmd)
	{
		make_pipe(fds, file_idx, simple_cmd);
		simple_cmd = simple_cmd->next;
		file_idx++;
	}
	delete_pipe_fds(fds);
	return (0);
}