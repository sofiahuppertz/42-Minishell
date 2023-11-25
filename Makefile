NAME	= minishell

INCLUDES = -I./headers -I./headers/Libft/headers


CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES) 


LIBFT = headers/Libft/libft.a

HELPERS = cmd_line_t/add_cmd_to_list.c \
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
	memory/delete_cmd_line.c \
	memory/delete_envp.c \
	memory/delete_tokens.c \
	pipe/duplicate_pipes.c \
	quotes/find_open_quotes.c \
	quotes/quotes_are_closed.c \
	redir/invalid_redirections.c \
	signals/init_signals.c \
	signals/signal_handlers.c \

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