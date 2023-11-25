
#include "../../headers/minishell.h"

int syntax_ok(char *str)
{
    if (!quotes_are_closed(str))
        return (0);
    if (duplicate_pipes(str))
        return (0);
    if (invalid_redirections(str))
        return (0);
    return (1);
}