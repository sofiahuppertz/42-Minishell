
#include "../../../headers/minishell.h"

int env(t_env *env, int fd)
{
    while (env && env->next)
    {
        if (envp_is_value_assigned(env->str))
            ft_putendl_fd(env->str, fd);
		env = env->next;
    }
    if (env)
		ft_putendl_fd(env->str, STDOUT);
	return (SUCCESS);
}