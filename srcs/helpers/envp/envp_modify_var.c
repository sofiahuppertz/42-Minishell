
#include "../../../headers/minishell.h"


// var name should include the "=". new_value should not include the "="
int envp_modify_var(const char *new_value, const char *var_name, t_env **env)
{
    t_env *current;
    size_t var_name_len;

    current = *env;
    var_name_len = ft_strlen(var_name);
    while (current)
    {
        if (ft_strncmp(current->str, var_name, var_name_len) == 0)
        {
            free(current->str);
            current->str = ft_strjoin(var_name, new_value);
            if (!current->str)
                return (1);
            return (0);
        }
        current = current->next;
    }
    return (-42);
}