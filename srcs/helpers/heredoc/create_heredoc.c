
#include "../../../headers/minishell.h"

int	create_heredoc_fd(t_cmd_line **simple_cmd, t_token **token)
{
    int		fd;
    char	*name_file;

    name_file = ".heredoc";
    fd = open(name_file, O_CREAT | O_EXCL | O_RDWR, 0644);
    if (fd == -1)
    {
        perror("Error creating heredoc");
        return (-1);
    }
    read_into_heredoc(fd, (*token)->str, (*token)->expanded);
    close(fd); 
    fd = open(name_file, O_RDONLY);
    (*simple_cmd)->fd_in = fd;
    if ((*simple_cmd)->name_file != NULL)
    {
        unlink((*simple_cmd)->name_file);
        ft_memdel((void *)(*simple_cmd)->name_file);
    }
    (*simple_cmd)->name_file = strdup(name_file);
    return (fd);
}