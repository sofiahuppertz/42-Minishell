
#include "../../../headers/minishell.h"

static int return_error(char c)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    if (c == '<')
        ft_putstr_fd("newline", 2);
    else
        ft_putchar_fd(c, 2);
    ft_putendl_fd("'", 2);
    return (1);
}

int invalid_redirections(char *str)
{
    int i = 0;
    char last_redirect = '\0';

    while (str[i])
    {
        if (str[i] == '<' || str[i] == '>')
        {
            if ((last_redirect != '\0' && last_redirect != str[i]) || 
                (i > 1 && str[i-1] == str[i] && str[i-2] == str[i]))
                {
                    if (!find_open_quotes(str, i))
                        return (return_error(str[i]));
                }
            last_redirect = str[i];
        }
        else if (str[i] != ' ')
            last_redirect = '\0';
        i++;
    }
    if (last_redirect != '\0')
        return (return_error(last_redirect));
    return (0);
}