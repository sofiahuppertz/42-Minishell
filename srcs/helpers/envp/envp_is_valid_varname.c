
#include "../../../headers/minishell.h"

int		envp_is_valid_varname(const char *env)
{
	int		i;

	if (ft_isdigit(env[0]) == 1)
		return (0);
    else if (env[0] == '=')
        return (-3);
    i = 0;
	while (env[i] && env[i] != '=')
	{
		if (ft_isalnum(env[i]) == 0)
			return (-1);
		i += 1;
	}
	if (env[i] != '=')
		return (2);
    else if (env[i] == '=' && env[i + 1] == '\0')
        return (3);
	return (1);
}