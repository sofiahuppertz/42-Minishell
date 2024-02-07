
#include "../../../headers/minishell.h"

int *cmd_in_progress(void)
{
	static int	new;

	return (&new);
}
