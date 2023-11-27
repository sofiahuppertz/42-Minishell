
#include "../../../headers/minishell.h"

static int	print_error(int status, const char *arg)
{
	int		i;

	if (status == -1)
		ft_putstr_fd("export: not valid in this context: ", 2);
	else if (status == 0 || status == -3)
		ft_putstr_fd("export: not a valid identifier: ", 2);
	i = 0;
	while (arg[i] && (arg[i] != '=' || status == -3))
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return (1);
}

static int  env_var_exists(const char *varname, t_env *env)
{
    int len;

    len = ft_strlen(varname);
    while (env)
    {
        if (ft_strncmp(env->str, varname, len) == 0)
            return (1);
        env = env->next;
    }
    return (0);
}


static char  *get_value(const char *arg, int status)
{
    char    *value;
    int     i;
    int     len;

    i = 0;
    if (status == 1)
    {
        while (arg[i] != '=')
            i++;
        len = ft_strlen(arg) - i;
        value = ft_substr(arg, i + 1, len);
    }
    else if (status == 2)
        value = ft_strdup("");
    else
        value = ft_strdup("\"\"");
    return (value);
}

static void print_env(t_env *env, int fd)
{
    char **sorted_env;
    int var;

    var = 0;
    sorted_env = envp_sort(env);;
    while (sorted_env[var])
    {
        ft_putstr_fd("declare -x ", fd);
        ft_putendl_fd(sorted_env[var], fd);
        var++;
    }
    ft_memdel((void *)sorted_env);
}

int			export(const char **args, t_env **env, int fd)
{
	int		status;
    char    *name;
    char    *value;

    status = 0;
    name = NULL;
    value = NULL;
	if (!args[1])
		print_env(*env, fd);
	else
	{
		status = envp_is_valid_varname(args[1]); 
		if (status <= 0)
			return (print_error(status, (const char *)args[1]));
        name = envp_get_var(args[1]); //extract name including "=". 
        if (env_var_exists((const char *)name, *env))
        {
            value = get_value(args[1], status);
            status = envp_modify_var((const char *)value, (const char *)name, env);
            ft_memdel(value);
        }
        else
        {
            if (status == 3)
            {
                value = ft_strjoin(args[1], "\"\"");
                status = envp_add_var((const char *)value, env);
                ft_memdel(value);
            }
            else
               status = envp_add_var((const char *)args[1], env);
        }
	}
    ft_memdel(name);
	return (status);
}

        //-1 (if not all alnum), 0 (if first idx is digit),
        // 1 (if it's a "normal" env)  or 2 (if no value is set)
        //-3 if first char is '='