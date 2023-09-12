/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_rube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:13:33 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/12 13:23:35 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	free_strs(char **result, int index)
{
	while (index-- > 0)
		free(result[index]);
	free(result);
}

int	ft_detect_quotes(const char *s, int i, char q)
{
	i += 1;
	while (s[i] && s[i] != q)
		i++;
	if (s[i] == q)
		i += 1;
	return (i);
}

int	ft_wordcount_quote(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			if (s[i] == '\"')
				i = ft_detect_quotes(s, i, '\"');
			else if (s[i] == '\'')
				i = ft_detect_quotes(s, i, '\'');
			else
			{
				while (s[i] && s[i] != c)
					i++;
			}
		}
		else
			i++;
	}
	return (words);
}

void	ft_take_quotes_word(char **strs, char const *s, int *word, int i[3])
{
	int		start;
	char	quote;

	quote = s[i[0]];
	i[0] += 1;
	start = i[0];
	while (s[i[0]] && s[i[0]++] != quote)
		i[1]++;
	strs[*word] = ft_substr(s, start, i[1]);
	if (!strs[*word])
		free_strs(strs, *word);
	*word = *word + 1;
}

char	**ft_take_words_quote(char **strs, char const *s, char c, int *word)
{
	int		i[3];	

	i[0] = 0;
	while (s[i[0]])
	{
		i[1] = 0;
		if (s[i[0]] != c && (s[i[0]] == '\'' || s[i[0]] == '\"'))
			ft_take_quotes_word(strs, s, word, i);
		else if (s[i[0]] != c)
		{
			i[2] = i[0];
			while (s[i[0]] && s[i[0]++] != c)
				i[1]++;
			strs[*word] = ft_substr(s, i[2], i[1]);
			if (!strs[*word])
			{
				free_strs(strs, *word);
				return (0);
			}
			*word = *word + 1;
		}
		else
			i[0]++;
	}
	return (strs);
}

char	**ft_split_quote(char const *s, char c)
{
	char	**strs;
	int		word;

	word = 0;
	strs = ft_calloc(sizeof(char *) * (ft_wordcount_quote(s, c) + 1), 1);
	if (!strs)
		return (0);
	strs = ft_take_words_quote(strs, s, c, &word);
	if (!strs)
		return (0);
	strs[word] = NULL;
	return (strs);
}

int main ()
{
	char **arr = ft_split_quote("awk -F ',' '{print \"$1\", $3}' datos.txt", ' ');
	for (size_t i = 0; arr[i] != NULL; i++)
		printf("%s\n", arr[i]);
	execve("/usr/bin/awk", arr, NULL);
}
