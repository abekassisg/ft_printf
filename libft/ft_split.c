/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:43:24 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/06 15:12:05 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free_array(char **array, int words_done)
{
	int	i;

	i = 0;
	while (i < words_done)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count_words++;
		i++;
	}
	return (count_words);
}

int	ft_word_length(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[start + i])
		i++;
	return (i);
}

char	*ft_word_create(char const *s, char c, int start)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((ft_word_length(s, c, start) + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (s[start + i] != c && s[start + i])
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i[2];

	if (s == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (s[i[0]])
	{
		if (s[i[0]] == c)
			i[0]++;
		else
		{
			array[i[1]] = ft_word_create(s, c, i[0]);
			if (array[i[1]] == NULL)
				return (ft_free_array(array, i[1]), NULL);
			i[0] += ft_word_length(s, c, i[0]);
			i[1]++;
		}
	}
	array[i[1]] = NULL;
	return (array);
}
