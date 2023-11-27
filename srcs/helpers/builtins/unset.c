
#include "../../../headers/minishell.h"

int unset(const char **args)
{
    int i = 1;
    while (args[i])
    {
        envp_remove_var(args[i], get_adress_envp());
        i++;
    }
    return (SUCCESS);
}