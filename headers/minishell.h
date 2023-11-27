
#ifndef MINISHELL_H
# define MINISHELL_H


# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft/Libft/headers/libft.h"

# define EXPANSION -36
# define SUCCESS 0
# define ERROR 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef enum mod
{
	GET,
	DELETE,
	FREE,
	ADD
}			t_mod;

typedef enum type
{
	NON,
	ARG,
	BUILTIN,
	INPUT,
	HEREDOC,
	LIMIT,
	TRUNC,
	APPEND,
	FILE_IN,
	FILE_TRUNC,
	FILE_APPEND,
	ENDS
}				t_type;

typedef struct	s_expansion
{
	char			*value;
	int				idx;
	int				new_idx;
}				t_expansion;

typedef struct			s_token
{
	char		*str;
	int		expanded;
	t_type	type;
	struct s_token		*next;
} t_token;

typedef struct				s_cmd_line
{
	char			*string;
	t_token			*first_token;
	char			**envp;
	char			**argv;
	int				fd_in;
	int				fd_out;
	char			*name_file;
	struct s_cmd_line	*next;
} t_cmd_line;

typedef struct		s_env
{
	char	*str;
	int		declare;
	struct s_env	*next;
} t_env;

typedef struct	s_sig
{
	int				sigint;
	int				sigquit;
	int				status;
	int				exit_shell;
	int				stop_exec;
	pid_t			pid;
}				t_sig;


int access_failure(char *command);
int add_spaces_to_delims(char **str);
int    break_simple_cmds(char *line, t_cmd_line **simple_cmd_list);
int				cd(const char **args, t_env **env);
int cmd_count(t_cmd_line *cmd_line);
int	create_heredoc(t_cmd_line **simple_cmd, t_token **token);
int	create_pipes(t_cmd_line **cmd_line);
int	dispatcher(t_cmd_line **cmd_line, pid_t *pid, int num_cmds);
int	duplicate_pipes(char *str);
int				echo(const char **args, int fd);
int env(t_env *env, int fd);
int envp_add_var(const char *new_variable, t_env **env);
int envp_count(t_env *env);
int		envp_is_valid_varname(const char *env);
int envp_is_value_assigned(const char *str);
int envp_modify_var(const char *new_value, const char *var_name, t_env **env);
int envp_remove_var(const char *var_name, t_env **env);
int	execution(t_cmd_line **full_cmd);
int		exec_builtin(const char **cmd_lst, int fd);
int exec_binary(char **args, t_cmd_line **cmd_line);
int	exit_cmd(const char **cmd);
int			export(const char **args, t_env **env, int fd);
int		find_open_quotes(char *line, int max_index);
int	fork_and_exec(pid_t *pid, int idx, t_cmd_line **cmd_line, t_cmd_line **simple_cmd);
int ft_execve(char *path, char **args, char **dirs, t_cmd_line **cmd_line);
int		get_token_length(char *str, int i);
int init_envp(char **envp);
int	init_signals(void);
int invalid_redirections(char *str);
int		is_builtin(char *command);
int		is_delim(char *line, int i);
int	make_pipe(int **fds, int idx, t_cmd_line *simple_cmd);
int parsing(char **str, t_cmd_line **line);
int		pwd(int fd);
int		quotes_are_closed(char *line);
int	read_into_heredoc(int fd, char *limitor);
int	redir(t_cmd_line **simple_cmd);
int redirect_heredoc(t_cmd_line **simple_cmd, t_token *token);
int	redirect_stdin(t_cmd_line **simple_cmd, t_token *token);
int	redirect_stdout(t_cmd_line **cmdl, t_token *token, short int flag);
int	set_file_types(t_cmd_line **full_cmd);
int	set_heredoc_limit(t_cmd_line **full_cmd);
int strcpy_expanded_var(t_expansion *x, char *arg, t_env *env);
int strlen_expanded_var(const char *arg, int idx, t_env *env);
int strlen_with_expansions(const char *arg, t_env *env);
int strlen_with_spaces(char *str);
int syntax_ok(char *str);
int	tokenize(t_cmd_line **cmd_list);
int	token_list_to_array(t_cmd_line **cmds);
int unset(const char **args);
int	wait_pid(t_cmd_line **cmd_line, pid_t *pid, int num_cmds);

char *envp_get_value(const char *var_name, t_env *env);
char *envp_get_var(const char *var);
char **envp_sort(t_env *env);

void add_cmd_to_list(char *str, int cur, int start, t_cmd_line **head);
void	close_fds(t_cmd_line **cmd_line);
void	cmd_list_add_back(t_cmd_line **head, t_cmd_line *last);
void	count_args_in_cmd(t_cmd_line *simple_cmd, int *len);
void	cpy_args_in_cmd(t_cmd_line *simple_cmd);
void	delete_cmd_line(t_cmd_line **cmd_line);
void	delete_envp();
void	delete_pipe_fds(int **fds);
void delete_tokens(t_token *head);
void    expansions(t_cmd_line **cmd_line);
void    init_shell_level();
void	init_type(t_token *new);
void    organize_redirections(t_cmd_line **full_cmd);
void read_command_line(char **line);
void realloc_str_and_expansions(char **arg, t_env *envp);
void	sig_int(int code);
void	sig_quit(int code);
void strcpy_adding_spaces(char **new, char *str);
void	strlen_simple_cmd(char *str, int *i);

t_env	**get_adress_envp(void);

t_token *create_node(int str_len);
t_token *get_next_token(char *str, int *idx);

extern t_sig g_sig;

#endif
