
#include "../headers/libft.h"

char *ft_strcpy(char *dest, const char *src)
{
    char *save;
    save = dest;
    while((*dest++ = *src++));
    return save;
}