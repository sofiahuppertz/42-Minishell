#include "../../../headers/minishell.h"

void realloc_str_and_expansions(char **arg, t_env *envp)
{
    t_expansion x;
    int new_len;

    new_len = strlen_with_expansions((const char *)*arg, envp);
    x.value = ft_calloc(sizeof(char), new_len + 1);
    if (!x.value)
        return ;
    x.new_idx = 0;
    x.idx = 0;
    while (x.new_idx < new_len && (*arg)[x.idx])
	{
		while ((*arg)[x.idx] == EXPANSION)
		{
			x.idx++;
			if (((*arg)[x.idx] == '\0' || !ft_isalnum((*arg)[x.idx]))
			&& (*arg)[x.idx] != '?')
				x.value[x.new_idx++] = '$';
			else
			{
				x.idx += strcpy_expanded_var(&x, *arg, envp);
				while (ft_isalnum((*arg)[x.idx]) || (*arg)[x.idx] == '_')
					x.idx++;
			}
		}
		x.value[x.new_idx++] = (*arg)[x.idx++];
	}
	x.value[x.new_idx] = '\0';
    free(*arg);
    *arg = x.value;
    return;
}