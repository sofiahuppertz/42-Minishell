/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:44:20 by shuppert          #+#    #+#             */
/*   Updated: 2024/02/18 17:58:37 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/Libft/headers/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
}								t_mod;

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
}								t_type;

typedef struct s_expansion
{
	char* value;
	int							idx;
	int							new_idx;
}								t_expansion;

typedef struct s_token
{
	char* str;
	int							expanded;
	t_type						type;
	struct s_token* next;
}								t_token;

typedef struct s_cmd_line
{
	char* string;
	t_token* first_token;
	char** envp;
	char** argv;
	int							fd_in;
	int							fd_out;
	char* name_file;
	struct s_cmd_line* next;
}								t_cmd_line;

typedef struct s_env
{
	char** envp;
	char* str;
	int							declare;
	struct s_env* next;
}								t_env;

int								add_spaces_to_delims(char** str);
int								cd(const char** args, t_env** env);
int								cmd_count(t_cmd_line* cmd_line);
int								create_pipes(t_cmd_line** cmd_line);
int								dispatcher(t_cmd_line** cmd_line, pid_t* pid,
	int num_cmds);
int								duplicate_pipes(char* str);
int								echo(const char** args, int fd);
int								env(t_env* env, int fd);
int								envp_count(t_env* env);
int								envp_is_valid_varname(const char* varname);
int								envp_is_value_assigned(const char* str);
int								envp_is_value_in_env(const char* value);
void							envp_print_sorted_env(t_env* env, int fd);
int								execution(t_cmd_line** full_cmd);
int								exec_builtin(const char** cmd_lst, int fd,
	int child);
int								exec_binary(char** args, t_cmd_line** cmd_line);
int								exit_cmd(const char** cmd);
int								export(const char** args, t_env** env, int fd);
int								find_open_quotes(char* line, int max_index);
int								fork_and_exec(pid_t* pid, int idx,
	t_cmd_line** cmd_line,
	t_cmd_line** simple_cmd);
int								ft_execve(char* path, char** args, char** dirs);
int								get_token_length(char* str, int i);
int								init_envp(char** envp);
int								init_signals(void);
int								invalid_redirections(char* str);
int								is_builtin(char* command);
int								is_delim(char* line, int i);
int								is_empty_line(char* str);
int								make_pipe(int** fds, int idx,
	t_cmd_line* simple_cmd);
int								parsing(char** str, t_cmd_line** line);
int								pwd(int fd);
int								quotes_are_closed(char* line);
int								read_into_heredoc(int fd, char* limitor);
int								redir(t_cmd_line** simple_cmd);
int								set_file_types(t_cmd_line** full_cmd);
int								set_heredoc_limit(t_cmd_line** full_cmd);
int								strcpy_expanded_var(t_expansion* x, char* arg,
	t_env* env);
int								strlen_expanded_var(const char* arg, int idx,
	t_env* env);

int								strlen_with_spaces(char* str);
int								syntax_ok(char* str);
int								tokenize(t_cmd_line** cmd_list);
int								token_list_to_array(t_cmd_line** cmds);
int								unset(const char** args);
int								wait_pid(t_cmd_line** cmd_line, pid_t* pid,
	int num_cmds);

char* envp_get_var(const char* var);
char** envp_sort(t_env* env);
void							access_failure(char* command);
void							add_cmd_to_list(char* str, int cur, int start,
	t_cmd_line** head);
void							close_fds(t_cmd_line** cmd_line);
void							cpy_args_in_cmd(t_cmd_line* simple_cmd);
void							delete_cmd_line(t_cmd_line** cmd_line);
void							dlt_cmdline_but_argv(t_cmd_line** cmd_line);
void							delete_envp(void);
void							delete_pipe_fds(int** fds);
void							delete_tokens(t_token* head);
void							envp_update_pwd(char* curr_dir, char* old_dir);
void							expansions(t_cmd_line** cmd_line);
void							init_shell_level(void);
void							init_type(t_token* new);
void							organize_redirections(t_cmd_line** full_cmd);
void							read_command_line(char** line);
void							run_shell();
void							sigint_handler(int code);
void							sigquit_handler(int code);
void							strcpy_adding_spaces(char** new, char* str);
void							strlen_simple_cmd(char* str, int* i);

int* cmd_in_progress(void);
int* status_pointer(void);
int* exit_shell(void);
int* stop_exec(void);

t_env** get_adress_envp(void);

t_token* create_node(int str_len);
t_token* get_next_token(char* str, int* idx);
char*** get_adress_char_envp(void);

int								break_cmds(char* line, t_cmd_line** list);
int								create_heredoc(t_cmd_line** s_cmd, t_token** t);
int								envp_add_var(const char* new, t_env** env);
int								e_modify_var(const char* new, const char* name,
	t_env** e);
int								remove_var(const char* var_name, t_env** env);
int								redir_heredoc(t_cmd_line** s_cmd, t_token* t);
int								r_stdin(t_cmd_line** s_cmd, t_token* t);
int								r_stdout(t_cmd_line** cmdl, t_token* t,
	short int f);
int								len_w_exp(const char* arg, t_env* env);
char* e_get_val(const char* var_name, t_env* env);
void							cmdl_add(t_cmd_line** head, t_cmd_line* last);
void							cmd_args_count(t_cmd_line* s_cmd, int* len);
void							expand_cmd(char** arg, t_env* envp);

extern volatile sig_atomic_t	g_caught_signal;

#endif
