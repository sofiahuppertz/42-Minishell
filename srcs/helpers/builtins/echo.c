
#include "../../../headers/minishell.h"

static	size_t		count_args(const char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int				echo(const char **args, int fd)
{
	size_t		i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (count_args(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (args[i])
		{
			if (ft_strcmp(args[i], "\"\"")) //not empty argument.
			{
				ft_putstr_fd((char *)args[i], fd);
				if (args[i + 1] && args[i][0] != '\0')
					ft_putchar_fd(' ', fd);
			}
			i++;
		}
	}
	if (n_option == 0)
		ft_putchar_fd('\n', fd);
	return (SUCCESS);
}
