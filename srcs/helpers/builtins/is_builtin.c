
#include "../../../headers/minishell.h"

int		is_builtin(char *command)
{
    if (!command)
        return (0);
    if (ft_strcmp(command, "cd") == 0)
        return (1);
    if (ft_strcmp(command, "echo") == 0)
        return (1);
    if (ft_strcmp(command, "env") == 0)
        return (1);
    if (ft_strcmp(command, "exit") == 0)
        return (1);
    if (ft_strcmp(command, "export") == 0)
        return (1);
    if (ft_strcmp(command, "pwd") == 0)
        return (1);
    if (ft_strcmp(command, "unset") == 0)
        return (1);
    return (0);
}
