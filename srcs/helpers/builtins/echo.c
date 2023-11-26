
#include "../../../headers/minishell.h"

static	size_t		count_args(const char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int				echo(char **args)
{
	size_t		i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (count_args((const char **)args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (args[i])
		{
			if (ft_strcmp(args[i], "\"\""))
			{
				ft_putstr_fd(args[i], 1);
				if (args[i + 1] && args[i][0] != '\0')
					write(1, " ", 1);
			}
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (SUCCESS);
}
