#include "../../../headers/minishell.h"

t_env	**get_adress_envp(void)
{
	static t_env	*new = NULL;

	return (&new);
}
