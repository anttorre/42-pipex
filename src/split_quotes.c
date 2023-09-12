/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:45:33 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/12 15:51:56 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	words_count2(char **str, char d, int flag, char aux);

void	free_split_quotes(char **arr)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

static size_t	words_count(char *str, char d)
{
	size_t	count;
	int		flag_quote;
	char	aux;

	count = 0;
	flag_quote = 0;
	while (*str)
	{
		while ((*str == d || *str == '\'' || *str == '\"') && *str != '\0')
		{
			if (*str == '\'' || *str == '\"')
			{
				aux = *str;
				flag_quote = !flag_quote;
			}
			str++;
		}
		if (*str != '\'' && *str != '\"' && *str != d)
			count++;
		words_count2(&str, d, flag_quote, aux);
	}
	return (count);
}

static	void	words_count2(char **str, char d, int flag, char aux)
{
	if (flag)
		while (**str != aux && **str)
			(*str)++;
	else
		while (**str != d && **str)
			(*str)++;
}

static	int	word_length(char *str, char d)
{
	int	i;
	int		flag_quote;
	char	aux;

	flag_quote = 0;
	i = 0;
	while ((str[i] != d && str[i] != '\0')
		{
			if (*str == '\'' || *str == '\"')
			{
				aux = *str;
				flag_quote = !flag_quote;
			}
			str++;
			if (flag_quote)
				while (*str != aux && *str)
					str++;
			else
				while (*str != d && *str)
					i++;
		}
	return (i);
}

static char	**split_loop(char *str, char d)
{
	char	**new_str;
	int		i;
	int		flag_quote;
	char	aux;

	i = -1;
	flag_quote = 0;
	new_str = ft_calloc(words_count(str, d) + 1, sizeof(char *));
	if (!new_str)
		return (NULL);
	while (*str)
	{
		
	}
	return (new_str);
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