
#include "../../../headers/minishell.h"

//str = readline("minishell$> ");
//add_history(str);
//signal(SIGINT, signal_cmd);
//signal(SIGQUIT, SIG_IGN);

void read_command_line(char **line)
{
	if (line == NULL)
		return ;
	if (g_sig.status == 0)
		*line = readline("\001\033[0m\033[1m\002🌹 minishell ▸ \001\033[0m\002");
	else
		*line = readline("\001\033[0m\033[1m\002💔 minishell ▸ \001\033[0m\002");

	if (*line == NULL)
	{
		ft_putstr_fd("\b\b", 1);
		ft_putendl_fd("exit 👋", 1);
        delete_envp();
		exit(0);
	}
	if ((*line) && (*line)[0] != '\0') 
		add_history(*line);
	return;
}