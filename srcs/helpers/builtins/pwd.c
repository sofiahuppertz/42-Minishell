
#include "../../../headers/minishell.h"

int		pwd(void)
{
	char	curr_dir[PATH_MAX];

	if (getcwd(curr_dir, PATH_MAX))
	{
		ft_putendl_fd(curr_dir, STDOUT);
		return (SUCCESS);
	}
	else
		return (ERROR);
}