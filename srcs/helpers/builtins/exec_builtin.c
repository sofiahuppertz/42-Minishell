
#include "../../../headers/minishell.h"

int		exec_builtin(const char **cmd_lst)
{
    int		result;

    if (!cmd_lst || !(*cmd_lst))
        return (0);
    if (!ft_strcmp(cmd_lst[0], "exit")) // && !has_pipe(token)
        result = exit_cmd(cmd_lst);
    else if (!ft_strcmp(cmd_lst[0], "echo"))
        result = echo(cmd_lst);
    else if (!ft_strcmp(cmd_lst[0], "cd"))
        result = cd(cmd_lst, get_adress_envp());
    else if (!ft_strcmp(cmd_lst[0], "pwd"))
        result = pwd();
    else if (ft_strcmp(cmd_lst[0], "env") == 0)
        result = env(*get_adress_envp());
    else if (ft_strcmp(cmd_lst[0], "export") == 0)
        result = export(cmd_lst, get_adress_envp());
    else 
        result = unset(cmd_lst);
    return (result);
}