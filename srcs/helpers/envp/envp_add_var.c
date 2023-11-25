
#include "../../../headers/minishell.h"

int envp_add_var(const char *new_variable, t_env **env)
{
    t_env *new_node;
    t_env *current;

    if (!env || !(new_node = ft_calloc(sizeof(t_env), 1)))
        return (-1);
    
    new_node->str = ft_strdup(new_variable);
    if (!new_node->str)
        return (1);
    new_node->next = NULL;
    if (*env == NULL)
        *env = new_node;
    else
    {
        current = *env;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    return (0);
}