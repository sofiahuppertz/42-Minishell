
#include "../headers/libft.h"

void ft_memdel_2d(void **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        ft_memdel(ptr[i]);
        i++;
    }
    free(ptr);
    ptr = NULL;
    return ;
}