
#include "../../../headers/minishell.h"

int strlen_expanded_var(const char *arg, int idx, t_env *env)
{
    char    varname[1025];
    char    *buffer;
    int     len;

    len = 0;
    if (arg[idx] == '?')
    {
        buffer = ft_itoa(g_sig.exit_status);
        len = ft_strlen(buffer);   
    }
    else if (ft_isdigit(arg[idx]))
        return 0;
    else
    {
        while(len < 1024 && arg[idx] && (ft_isalnum(arg[idx]) || arg[idx] == '_'))
            varname[len++] = arg[idx++];
        varname[len] = '\0';
        buffer = envp_get_value((const char *)varname, env);
        if (!buffer)
            len = 0;
        else
            len = ft_strlen(buffer);
    }
    ft_memdel(buffer);
    return (len);
}