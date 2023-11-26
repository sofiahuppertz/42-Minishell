
#include "../../../headers/minishell.h"

int		exec_builtin(char **cmd_lst, t_mini *shell, t_token *token)
{
    int		result;
    (void)token;

    if (!ft_strcmp(cmd_lst[0], "exit")) // && !has_pipe(token)
        result = exit_cmd(shell, cmd_lst);
    else if (!ft_strcmp(cmd_lst[0], "echo"))
        result = echo(cmd_lst);
    else if (!ft_strcmp(cmd_lst[0], "cd"))
        result = cd(cmd_lst, &(shell->env));
    else if (!ft_strcmp(cmd_lst[0], "pwd"))
        result = pwd();
    else if (ft_strcmp(cmd_lst[0], "env") == 0)
        result = env(shell->env);
    else if (ft_strcmp(cmd_lst[0], "export") == 0)
        result = export(cmd_lst, &(shell->env));
    else 
        result = unset(cmd_lst, shell);
    return (result);
}