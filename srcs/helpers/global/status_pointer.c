
#include "../../../headers/minishell.h"

int *status_pointer(void)
{
	static int	new;

	return (&new);
}