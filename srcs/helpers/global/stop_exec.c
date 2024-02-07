
#include "../../../headers/minishell.h"

int *stop_exec(void)
{
	static int	new;

	return (&new);
}