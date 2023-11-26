NAME	= minishell

INCLUDES = -I./headers -I./headers/Libft/headers


CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES) 


LIBFT = headers/Libft/libft.a

HELPERS = builtins/is_builtin.c \
	cmd_line_t/add_cmd_to_list.c \
	cmd_line_t/break_simple_cmds.c \
	cmd_line_t/cmd_list_add_back.c \
	cmd_line_t/strlen_simple_cmd.c \
	command_line/read_command_line.c \
	envp/envp_add_var.c \
	envp/envp_get_value.c \
	envp/envp_modify_var.c \
	envp/get_adress_envp.c \
	envp/init_envp.c \
	envp/init_shell_level.c \
	expansions/expansions.c \
	expansions/realloc_str_and_expansions.c \
	expansions/strcpy_expanded_var.c \
	expansions/strlen_expanded_var.c \
	expansions/strlen_with_expansions.c \
	memory/delete_cmd_line.c \
	memory/delete_envp.c \
	memory/delete_tokens.c \
	pipe/duplicate_pipes.c \
	quotes/find_open_quotes.c \
	quotes/quotes_are_closed.c \
	redir/invalid_redirections.c \
	redir/is_delim.c \
	redir/organize_redirections.c \
	redir/set_file_types.c \
	redir/set_heredoc_limit.c \
	signals/init_signals.c \
	signals/signal_handlers.c \
	spaces/add_spaces_to_delims.c \
	spaces/strcpy_adding_spaces.c \
	spaces/strlen_with_spaces.c \
	tokens/count_args_in_cmd.c \
	tokens/cpy_args_in_cmd.c \
	tokens/create_node.c \
	tokens/get_next_token.c \
	tokens/get_token_length.c \
	tokens/init_type.c \
	tokens/token_list_to_array.c \
	tokens/tokenize.c \

PARSING = parsing.c \
		syntax_ok.c \

MAIN = main.c

SRC_NAMES = $(addprefix helpers/, $(HELPERS)) \
			$(addprefix parsing/, $(PARSING)) \
       $(MAIN)

SRCS = $(addprefix srcs/, $(SRC_NAMES))
OBJS = $(SRCS:c=o)

all		: $(NAME)

$(LIBFT):
	make -C headers/Libft

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -lreadline $(LIBFT)

%.o: srcs/%.c
	cc -g $(CFLAGS) -c $< -o $@

fclean	: clean
	rm -f $(NAME) 

clean:
	make fclean -C headers/Libft clean
	rm -f $(OBJS)

re		: fclean all

.PHONY: clean fclean all re