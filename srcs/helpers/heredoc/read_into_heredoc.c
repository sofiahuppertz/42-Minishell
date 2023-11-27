
#include "../../../headers/minishell.h"

int	read_into_heredoc(int fd, char *limitor)
{
	char	*here_line;
    t_env   *envp;

    envp = *get_adress_envp();
	while (1)
	{
		here_line = readline("> ");
		if (here_line == NULL)
			return 0;
		if (ft_strcmp(limitor, here_line) == 0)
			break ;
		if (here_line[0] != '\0')
			realloc_str_and_expansions(&here_line, envp);
		ft_putendl_fd(here_line, fd);
		ft_memdel((void *)here_line);
	}
	ft_memdel((void *)here_line);
	return (0);
}