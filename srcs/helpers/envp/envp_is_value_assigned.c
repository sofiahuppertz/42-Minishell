
#include "../../../headers/minishell.h"

int envp_is_value_assigned(const char *str)
{
    char *ptr;

    ptr = ft_strchr(str, '=');
    if (ptr && *(ptr + 1) != '\0')
        return (1);
    return (0);
}
