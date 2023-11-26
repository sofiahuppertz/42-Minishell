
#include "../../../headers/minishell.h"

int unset(char **args, t_mini *shell)
{
    int i = 1;
    while (args[i])
    {
        envp_remove_var(args[i], &(shell->env));
        i++;
    }
    return (SUCCESS);
}