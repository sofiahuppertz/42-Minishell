
#include "../../../headers/minishell.h"

int envp_count(t_env *env)
{
    int count = 0;
    while (env && env->next)
    {
        count++;
        env = env->next;
    }
    return count;
}
