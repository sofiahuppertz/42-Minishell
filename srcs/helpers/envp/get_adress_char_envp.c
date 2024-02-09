
#include "../../../headers/minishell.h"

char ***get_adress_char_envp(void)
{
	static char	**new;

	return (&new);
}
