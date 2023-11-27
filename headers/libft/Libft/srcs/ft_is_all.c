
#include "../headers/libft.h"

int ft_is_all(const char *str, int (*f)(int))
{
    while (*str)
    {
        if (!f(*str))
            return (0);
        str++;
    }
    return (1);
}