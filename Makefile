NAME	= minishell

INCLUDES = -I./headers -I./headers/Libft/headers


CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES) 


LIBFT = headers/Libft/libft.a

HELPERS = command_line/read_command_line.c \
	envp/envp_add_var.c \
	envp/envp_get_value.c \
	envp/envp_modify_var.c \
	envp/get_adress_envp.c \
	envp/init_envp.c \
	envp/init_shell_level.c \
	memory/delete_cmd_line.c \
	memory/delete_envp.c \
	memory/delete_tokens.c \
	signals/init_signals.c \
	signals/signal_handlers.c \

MAIN = main.c

SRC_NAMES = $(addprefix helpers/, $(HELPERS)) \
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