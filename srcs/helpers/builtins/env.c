
#include "../../../headers/minishell.h"

int env(t_env *env)
{
    while (env && env->next)
    {
        if (envp_is_value_assigned(env->value))
            ft_putendl_fd(env->value, STDOUT);
		env = env->next;
    }
    if (env)
		ft_putendl_fd(env->value, STDOUT);
	return (SUCCESS);
}