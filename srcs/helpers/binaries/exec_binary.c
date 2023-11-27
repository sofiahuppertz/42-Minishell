
#include "../../../headers/minishell.h"

static char *search_path_for_command(char **dirs, char *command)
{
    char *path;
    char *temp;
    int i = 0;

    while (dirs[i]) 
    {
        temp = ft_strjoin(dirs[i], "/");
        path = ft_strjoin(temp, command);
        free(temp);
        if (access(path, X_OK) == 0) 
            return path;
        else if (errno != ENOENT)
        {
            free(path);
            return NULL;
        }
        free(path);
        i++;
    }
    return NULL;
}

int exec_binary(char **args, t_cmd_line **cmd_line)
{
    char *path;
    char **dirs;

    dirs = ft_split(getenv("PATH"), ':');
    if (access(args[0], X_OK) == 0) 
    {
        ft_execve(args[0], args, dirs, cmd_line);
    } 
    else 
    {    
        path = search_path_for_command(dirs, args[0]);
        if (path != NULL) 
        {
            
            ft_execve(path, args, dirs, cmd_line);   
            ft_memdel(path);
        }
        else
            g_sig.status = access_failure(args[0]);
    }
    ft_memdel_2d((void **)dirs);
    return 0;
}