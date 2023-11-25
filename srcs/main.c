
#include "../headers/minishell.h"

t_sig  g_sig;

int	main(int argc, char **argv, char **envp)
{
	char			*str;
	t_cmd_line      *full_cmd;

	full_cmd = NULL;
	init_envp(envp);
	//print envp
	//t_env *tmp = *get_adress_envp();
	//while (tmp)
	//{
	//	printf(" %s\n", tmp->str);
	//	printf("declare = %d\n", tmp->declare);
	//	tmp = tmp->next;
	//}
	while (1)
	{
		init_signals();	
        read_command_line(&str);
        if (parsing(str, &full_cmd))
			;
		
            //if (!execution())
            //    error_exec();
		ft_memdel((void*)str);
		delete_cmd_line(&full_cmd);
	}
    (void)argc;
    (void)argv;
}