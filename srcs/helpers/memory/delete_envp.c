
#include "../../../headers/minishell.h"
void	delete_envp()
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *get_adress_envp();
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		ft_memdel(tmp->str);
		ft_memdel(tmp);
	}
    return;
}