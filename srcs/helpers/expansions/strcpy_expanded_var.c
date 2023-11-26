
#include "../../../headers/minishell.h"

static  char *get_expanded_var(char *arg, int idx, t_env *env)
{
    char	var_name[1025];
	char	*var_value;
	int		i;

	i = 0;
	if (arg[idx] == '?')
	{
		var_value = ft_itoa(g_sig.status);
		return (var_value);
	}
	if (ft_isdigit(arg[idx]))
		return (NULL);
	while (arg[idx] &&  (ft_isalnum(arg[idx]) || arg[idx] == '_') && i < 1024)
	{
		var_name[i] = arg[idx];
		idx++;
		i++;
	}
	var_name[i] = '\0';
	var_value = envp_get_value(var_name, env);
	return (var_value);
}

int strcpy_expanded_var(t_expansion *x, char *arg, t_env *env)
{
    char    *buffer;

    buffer = get_expanded_var(arg, x->idx, env);
    if (buffer) 
    {
		ft_strcpy(x->value + x->new_idx, buffer);
		x->new_idx += ft_strlen(buffer);
	}
	free(buffer);
	if (arg[x->idx] == '?') {
		x->idx++;
	}
	if (!ft_isdigit(arg[x->idx]) && arg[x->idx - 1] != '?')
    {
		while (ft_isalnum(arg[x->idx] || arg[x->idx] == '_'))
			x->idx++;
	} 
	else 
		if (arg[x->idx - 1] != '?')
			x->idx++;
	return (0);
}
