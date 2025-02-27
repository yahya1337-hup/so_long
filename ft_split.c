/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboumei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:15:59 by yaboumei          #+#    #+#             */
/*   Updated: 2025/02/26 20:16:02 by yaboumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(const char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			word++;
		while (*s && (*s != c))
			s++;
	}
	return (word);
}

static const char	*char_num(const char *s, char c, int *le)
{
	while (*s && (*s != c))
	{
		s++;
		(*le)++;
	}
	return (s);
}

static char	**full_word(char const *s, char **words, char c, int size)
{
	int			le;
	int			i;
	int			j;
	const char	*start;

	i = 0;
	while (*s && i < size)
	{
		j = 0;
		le = 1;
		while (*s && ((char)*s == c))
			s++;
		if (*s)
			start = s;
		s = char_num(s, c, &le);
		words[i] = malloc(sizeof(char) * le);
		if (!words[i])
			return (NULL);
		while (start != s)
			words[i][j++] = *start++;
		words[i++][j] = '\0';
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (s == NULL)
		return (NULL);
	words = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!words)
		return (NULL);
	words[count_word(s, c)] = NULL;
	return (full_word(s, words, c, count_word(s, c)));
}
/*#include <stdio.h>

int	main(void)
{
	const char	*str = "#Hello, this is a test string.#";
	char		delimiter;
	char		**result;

	delimiter = '#';
	// Call ft_split to split the string
	result = ft_split(str, delimiter);
	if (result)
	{
		// Print the resulting words
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("Word %d: %s\n", i, result[i]);
			// free(result[i]); // Free each individual word
		}
		// free(result); // Free the array of pointers
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}*/
