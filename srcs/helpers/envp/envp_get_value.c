
#include "../../../headers/minishell.h"

//A str type copy of the value of a variable, returns the str after the "="
char *envp_get_value(const char *var_name, t_env *env)
{
    t_env *current;
    char *str;
    size_t len;

    current = env;
    len = ft_strlen(var_name);
    while (current)
    {
        if (ft_strncmp(current->str, var_name, len) == 0)
        {
            str = current->str;
            while(*str != '=')
                str++;
            if (*(str + 1) == '\0')
                return ft_strdup("");
            return ft_strdup(str + 1);
        }        
        current = current->next;
    }
    return (NULL);
}