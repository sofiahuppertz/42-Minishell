
#include "../../../headers/minishell.h"

static void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

char **envp_sort(t_env *env)
{
    int count; 
    char **sorted_envp;
    int i;
    int j;
    
    count = envp_count(env) + 1;
    sorted_envp = ft_calloc(sizeof(char *), count);
    if (!sorted_envp)
        return NULL;
    i = 0;
    while( env && i < count)
    {
        sorted_envp[i] = env->str;
        env = env->next;
        i += 1;
    }
    sorted_envp[count] = NULL;
    i = 0;
    while(i < count - 1)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (ft_strcmp(sorted_envp[j], sorted_envp[j + 1]) > 0)
                swap(&sorted_envp[j], &sorted_envp[j + 1]);
            j += 1;
        }
        i += 1;
    }
    return sorted_envp;
}
