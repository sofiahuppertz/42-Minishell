/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:47:20 by shuppert          #+#    #+#             */
/*   Updated: 2023/11/29 12:37:32 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static size_t	count_args(const char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

static int	handle_n_option(const char **args, size_t *idx)
{
	int	n_option;
	int	n_idx;

	n_option = 0;
	while (args[*idx] && args[*idx][0] == '-')
	{
		n_idx = 1;
		while (args[*idx][n_idx] == 'n')
			n_idx++;
		if (args[*idx][n_idx] == '\0')
			n_option = 1;
		else
			break ;
		(*idx)++;
	}
	return (n_option);
}

static void	print_args(const char **args, int fd, size_t *i)
{
	while (args[*i])
	{
		if (ft_strcmp(args[*i], "\"\""))
		{
			ft_putstr_fd((char *)args[*i], fd);
			if (args[*i + 1] && args[*i][0] != '\0')
				ft_putchar_fd(' ', fd);
		}
		(*i)++;
	}
}

int	echo(const char **args, int fd)
{
	size_t	i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (count_args(args) > 1)
	{
		n_option = handle_n_option(args, &i);
		print_args(args, fd, &i);
	}
	if (n_option == 0)
		ft_putchar_fd('\n', fd);
	return (SUCCESS);
}
