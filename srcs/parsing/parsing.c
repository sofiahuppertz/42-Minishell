
#include "../../../headers/minishell.h"

int parsing(char *str, t_cmd_line **line)
{
	//int	res;
	
    //check syntax -> double pipes, delims...
    if (!syntax_ok(str))
    {
        g_sig.exit_status = 258;
        return (0);
    }
	add_spaces_to_delims(str);
    break_simple_cmds(str, line);
	tokenize_simple_cmds(line);
	// ->  reorganize_tokens(line);
	token_list_to_array(line);

	return (0);
}
