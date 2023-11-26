
#include "../../../headers/minishell.h"

void	delete_fds(int **fds)
{
    int	i;

    i = 0;
    while (fds[i])
    {
        free(fds[i]);
        i++;
    }
    free(fds);
}
