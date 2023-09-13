/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:45:33 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/13 14:37:47 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**split_loop(char *str, char d)
{
	char	**new_str;
	int		i;
	int		flag_quote;
	char	aux;
	int		wl;

	i = -1;
	flag_quote = 0;
	new_str = ft_calloc(words_count(str, d) + 1, sizeof(char *));
	if (!new_str)
		return (NULL);
	while (*str)
	{
		iterator_quotes(&str, d, &aux, &flag_quote);
		while ((*str != aux && flag_quote)
			|| (*str != d && !flag_quote && *str))
		{
			wl = word_length(str, d, flag_quote, aux);
			new_str[++i] = ft_substr(str, 0, wl);
			if (!new_str[i])
				return (free_split_quotes(new_str), NULL);
			str += wl;
		}
	}
	return (new_str[++i] = NULL, new_str);
}

char	**ft_split_quotes(char *str, char d)
{
	char	**arr;

	arr = split_loop(str, d);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}
//  awk -F ',' '{print $1, $3}' datos.txt
void ft_leaks()
{
	system("leaks -q split_quotes");
}

int main()
{
	atexit(ft_leaks);
	char **i = ft_split_quotes("awk -F ',' '{print $1, $3}' datos.txt", ' ');
	if (!i)
		return (1);
	return (free_split_quotes(i), 0);
}
