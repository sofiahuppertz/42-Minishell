
#include "../../../headers/minishell.h"

int strlen_with_expansions(const char *arg, t_env *env)
{
    int len;
    int idx;

    len = 0;
    idx = 0;
    while (arg[idx])
    {
        while (arg[idx] == EXPANSION)
        {
            idx++;
            if ((!arg[idx] || !ft_isalnum(arg[idx])) && arg[idx] != '?')
                len++;
            else
                len += strlen_expanded_var(arg, idx, env);
            if (!ft_isdigit(arg[idx]))
			{
				while (arg[idx + 1] && (ft_isalnum(arg[idx]) || arg[idx] == '_'))
					idx++;
			}
			else
				len -= 1;
        }
        len++;
        idx++;
    }
    return (len);
}