
#include "../headers/minishell.h"

t_sig  g_sig;

int	main(int argc, char **argv, char **envp)
{
	char			*str;
	t_cmd_line      *full_cmd;

	full_cmd = NULL;
	init_envp(envp);
	while (!g_sig.exit_shell)
	{
		init_signals();	
        read_command_line(&str);
		if (str != NULL)
			parsing(&str, &full_cmd);
		if (g_sig.status != 258 && full_cmd != NULL)
			execution(&full_cmd);
		ft_memdel((void*)str); //Not sure about this but I think yeah
		str = NULL;
		delete_cmd_line(&full_cmd);
	}
    (void)argc;
    (void)argv;
}