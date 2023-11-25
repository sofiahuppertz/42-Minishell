#include "../../../headers/minishell.h"

void    init_shell_level()
{
    int    shell_level;
    char *temp;

    temp = envp_get_value("SHLVL", *get_adress_envp());
    if (temp)
    {
        if (!ft_is_all(temp, &ft_isdigit))
        {
            free(temp);
            return;
        }  
        shell_level = ft_atoi(temp);
        if (shell_level >= 0)
        {
            free(temp);
            temp = ft_itoa(shell_level + 1);
            envp_modify_var(temp, "SHLVL=", get_adress_envp());
        }
        free(temp);
    }
    else
        return ;
}