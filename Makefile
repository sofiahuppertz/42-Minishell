NAME	= minishell

INCLUDES = -I./headers -I./headers/Libft/headers


CFLAGS = -g3 -Wall -Wextra -Werror $(INCLUDES)


LIBFT = headers/libft/Libft/libft.a

HELPERS = binaries/access_failure.c \
	binaries/exec_binary.c \
	binaries/ft_execve.c \
	builtins/cd.c \
	builtins/echo.c \
	builtins/env.c \
	builtins/exec_builtin.c \
	builtins/exit.c \
	builtins/export.c \
	builtins/is_builtin.c \
	builtins/pwd.c \
	builtins/unset.c \
	cmd_line_t/add_cmd_to_list.c \
	cmd_line_t/break_cmds.c \
	cmd_line_t/cmd_count.c \
	cmd_line_t/cmdl_add.c \
	cmd_line_t/strlen_simple_cmd.c \
	command_line/read_command_line.c \
	envp/envp_add_var.c \
	envp/envp_count.c \
	envp/e_get_val.c \
	envp/envp_get_var.c \
	envp/envp_is_valid_varname.c \
	envp/envp_is_value_assigned.c \
	envp/envp_is_value_in_env.c \
	envp/e_modify_var.c \
	envp/envp_print_sorted_env.c \
	envp/envp_to_char.c \
	envp/remove_var.c \
	envp/envp_sort.c \
	envp/get_adress_char_envp.c \
	envp/envp_update_pwd.c \
	envp/get_adress_envp.c \
	envp/init_envp.c \
	envp/init_shell_level.c \
	expansions/expansions.c \
	expansions/expand_cmd.c \
	expansions/strcpy_expanded_var.c \
	expansions/strlen_expanded_var.c \
	expansions/len_w_exp.c \
	file/close_fds.c \
	fork/fork_and_exec.c \
	fork/wait_pid.c \
	global/cmd_in_progress.c \
	global/exit_shell.c \
	global/get_heredoc_flag.c \
	global/status_pointer.c \
	global/stop_exec.c \
	heredoc/create_heredoc.c \
	heredoc/read_into_heredoc.c \
	memory/delete_cmd_line.c \
	memory/dlt_cmdline_but_argv.c \
	memory/delete_char_envp.c \
	memory/delete_envp.c \
	memory/delete_pipe_fds.c \
	memory/delete_tokens.c \
	pipe/create_pipes.c \
	pipe/duplicate_pipes.c \
	pipe/make_pipe.c \
	quotes/find_open_quotes.c \
	quotes/quotes_are_closed.c \
	redir/invalid_redirections.c \
	redir/is_delim.c \
	redir/organize_redirections.c \
	redir/redir.c \
	redir/redir_heredoc.c \
	redir/r_stdin.c \
	redir/r_stdout.c \
	redir/set_file_types.c \
	redir/set_heredoc_limit.c \
	shell/run_shell.c \
	signals/init_signals.c \
	signals/signal_handlers.c \
	spaces/add_spaces_to_delims.c \
	spaces/is_empty_line.c \
	spaces/strcpy_adding_spaces.c \
	spaces/strlen_with_spaces.c \
	tokens/cmd_args_count.c \
	tokens/cpy_args_in_cmd.c \
	tokens/create_node.c \
	tokens/get_next_token.c \
	tokens/get_token_length.c \
	tokens/init_type.c \
	tokens/token_list_to_array.c \
	tokens/tokenize.c

PARSING = parsing.c \
	syntax_ok.c

EXEC =	dispatcher.c \
	execution.c

MAIN = main.c

SRC_NAMES = $(addprefix helpers/, $(HELPERS)) \
			$(addprefix parsing/, $(PARSING)) \
			$(addprefix exec/, $(EXEC)) \
       $(MAIN)

SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:c=o)

all		: $(NAME)

$(LIBFT):
	make -C headers/libft/Libft

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -lreadline $(LIBFT)

%.o: srcs/%.c
	cc $(CFLAGS) -c $< -o $@

fclean	: clean
	rm -f $(NAME)

clean:
	make fclean -C headers/libft/Libft clean
	rm -f $(OBJS)

re		: fclean all

.PHONY: clean fclean all re
