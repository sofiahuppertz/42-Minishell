
#include "../../../headers/minishell.h"

void    organize_redirections(t_cmd_line **full_cmd)
{
    set_heredoc_limit(full_cmd);
    set_file_types(full_cmd);
    return;
}
