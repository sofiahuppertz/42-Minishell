
#include "../../../headers/minishell.h"

static void print_redir_error(char c)
{
    ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
    ft_putchar_fd(c, 2);
    ft_putendl_fd("'", 2);
    return;
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
                    {
                        print_redir_error(str[i]);
                        return (1);
                    }          
                }
            last_redirect = str[i];
        }
        else if (str[i] != ' ')
            last_redirect = '\0';
        i++;
    }
    return (0);
}