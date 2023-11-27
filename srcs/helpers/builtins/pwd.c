
#include "../../../headers/minishell.h"

int		pwd(int fd)
{
	char	curr_dir[PATH_MAX];

	if (getcwd(curr_dir, PATH_MAX))
	{
		ft_putendl_fd(curr_dir, fd);
		return (SUCCESS);
	}
	else
		return (ERROR);
}