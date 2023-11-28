
#include "../../../headers/minishell.h"

int envp_is_value_in_env(const char *value)
{
    t_env *env;
    int len;

    env = *get_adress_envp();
    len = ft_strlen(value);
    while (env)
    {
        if (ft_strncmp(env->str, value, len) == 0)
            return (1);
        env = env->next;
    }
    return (0);    
}