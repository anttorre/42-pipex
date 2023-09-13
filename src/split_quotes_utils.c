/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:21:43 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/13 13:13:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	words_count2(char **str, char d, int flag, char aux);
static	void	word_length2(char *str, char d, int *flag_quote, char aux);

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

size_t	words_count(char *str, char d)
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

int	word_length(char *str, char d, int flag, char c)
{
	int		flag_quote[2];
	char	aux;

	flag_quote[0] = flag;
	flag_quote[1] = 0;
	while ((*str == d || *str == '\'' || *str == '\"') && *str != '\0')
	{
		if (*str == '\'' || *str == '\"')
		{
			aux = *str;
			flag_quote[0] = !flag_quote[0];
		}
		str++;
	}
	word_length2(str, d, flag_quote, aux);
	return (flag_quote[1]);
}

static	void	word_length2(char *str, char d, int *flag_quote, char aux)
{
	if (flag_quote[0])
	{
		while (*str != aux && *str)
		{
			flag_quote[1]++;
			str++;
		}
	}
	else
	{
		while (*str != d && *str)
		{
			flag_quote[1]++;
			str++;
		}
	}
}
