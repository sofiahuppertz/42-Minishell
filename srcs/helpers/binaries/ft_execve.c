
#include "../../../headers/minishell.h"

int ft_execve(char *path, char **args, char **dirs, t_cmd_line **cmd_line)
{

    if (execve(path, args, dirs) == -1) 
    {
       ft_putstr_fd("minishell: ", 2);
       ft_putstr_fd(args[0], 2);
       ft_putstr_fd(": ", 2);
       ft_putstr_fd(strerror(errno), 2);
       ft_putstr_fd("\n", 2);
       ft_memdel_2d((void **)dirs);
       ft_memdel_2d((void **)args);
       ft_memdel((void *)path);
       delete_cmd_line(cmd_line);
       delete_envp();
       exit(ERROR);
    }
    return ERROR;
}
