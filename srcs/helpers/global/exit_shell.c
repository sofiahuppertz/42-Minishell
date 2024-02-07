
#include "../../../headers/minishell.h"

int *exit_shell(void)
{
	static int	new;

	return (&new);
}