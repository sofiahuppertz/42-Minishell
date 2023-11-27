#include "../headers/libft.h"

int	ft_iswhitespace(int c)
{
    if (c == 32 || c == 9 || c == 11 || c == 12 || c == 13 || c == 10)
    {
        return (1);
    }
    return (0);
}