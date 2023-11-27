
#include "../../../headers/minishell.h"

char *envp_get_var(const char *var)
{
    int len;
    char *result;

    len = ft_strrchr(var, '=') - var + 1;
    result = ft_substr(var, 0, len);
    return (result);
}