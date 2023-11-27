
#include "../../../headers/minishell.h"

int    is_empty_line(char *str)
{
    int index;

    index = 0;
    index = ft_add_while_true(index, str, &ft_iswhitespace);
    if (str[index] == '\0')
        return (1);
    return (0);
}
