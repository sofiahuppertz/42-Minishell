#include "../headers/libft.h"

int    ft_add_while_true(int a, char *str, int (*f)(int))
{
    if (!str)
        return (0);
    while (str[a] != '\0' && f(str[a]))
        a++;
    return (a);
}