/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:43:45 by shuppert          #+#    #+#             */
/*   Updated: 2023/07/19 13:10:53 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	free_all(char **str, int size)
{
	while (size >= 0)
	{
		free(str[size]);
		size--;
	}
	free(str);
	return (-1);
}

static void	copy_word(char *word, const char *start, char stop)
{
	int	i;

	i = 0;
	while (start[i] != stop && start[i] != 0)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = 0;
}

static int	make_tab(const char *s, char **dest, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != 0)
	{
		if (s[i] == c || s[i] == 0)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			dest[word] = (char *)malloc((j + 1) * sizeof(char));
			if (!dest[word])
				return (free_all(dest, word - 1));
			copy_word(dest[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0') == 1
			&& (str[i] == charset || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;

	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[words] = 0;
	if (make_tab(s, result, c) == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
