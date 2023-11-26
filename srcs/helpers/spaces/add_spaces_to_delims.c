
#include "../../../headers/minishell.h"

int add_spaces_to_delims(char **str) 
{
    int new_len; 
    char *new_str; 

	new_len = strlen_with_spaces(*str);
	new_str = ft_calloc(sizeof(char), new_len);
    if (!new_str)
	{
		free(*str);
		return 0;
	}
    strcpy_adding_spaces(&new_str, *str);
	ft_memdel((void *)*str);
	*str = new_str;
    return 1;
}