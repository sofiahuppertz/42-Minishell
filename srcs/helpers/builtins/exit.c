
#include "../../../headers/minishell.h"

int	exit_cmd(t_mini *shell, char **cmd)
{
    shell->exit_shell = 1;
	ft_putendl_fd("exit 👋", STDERR);
    if (cmd[1] && ft_is_all(cmd[1], &ft_isdigit) && cmd[2])
    {
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
        shell->exit_shell = 0;
        return (ERROR);
    }
	else if (cmd[1]) 
	{
        if (!(ft_is_all(cmd[1], &ft_isdigit)))
        {
            ft_putstr_fd("minishell: exit: ", STDERR);
            ft_putstr_fd(cmd[1], STDERR);
            ft_putendl_fd(": numeric argument required", STDERR);
            return (255);
        }
        else
            return(ft_atoi(cmd[1]));
	}
    return (SUCCESS);
}