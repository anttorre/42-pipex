/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:09:34 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 12:47:01 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * mientras que la cadena no sea nula y sea igual al delimitador
 * avanzo el puntero, si es distinto de '\0' sumo una palabra y
 * mientras que el caracter no sea el delimitador y no sea '\0'
 * avanzo el puntero para ir contando el resto de palabras
 * 
 * @param s const char * | puntero a la cadena
 * @param c char | delimitador por el que cortar
 * @return size_t | numero de palabras contadas en la cadena
 */
static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

/**
 * @brief 
 * Libera todas las reservas de memoria dende donde fallo un indice
 * 
 * @param arr char ** | puntero a un arreglo (array bidimensional)
 * @param index size_t | indice donde fallo la reserva de memoria
 */
static void	ft_free_split(char **arr, size_t index)
{
	size_t	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < index)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

/**
 * @brief 
 * Cuenta la cantidad de caracteres que tiene la palabra
 * mientras que el caracter sea distinto del delimitador y 
 * no sea '\0'
 * 
 * @param s const char * | puntero a la cadena
 * @param delimiter char | caracter delimitador
 * @return size_t | cantidad de caracteres
 */
static size_t	word_length(const char *s, char delimiter)
{
	size_t	len;

	len = 0;
	while (s[len] != delimiter && s[len] != '\0')
		len++;
	return (len);
}

/**
 * @brief 
 * Mientras que la caena no sea '\0' vamos a recorrerla, mientras que
 * sea igual que el delimitador y distinto de nulo avanzo el puntero, si
 * encuentra un nulo me salgo del bucle, asigno a word_len el tamaño de la
 * cadena, en el array bidimensional en la primero posicion asigno memoria
 * para la palabra si no se produce libero memoria desde donde fallo y devuevlo
 * BULL, si no uso la funcion ft_strlcpy y en el indice del array copio desde
 * donde apunta mi cadena hasta el tamaño de la palabra + 1, despues avanzo el
 * puntero sumandole word_len, la ultima posicion del array debe ser NULL y por
 * ultimo devolvemos el arreglo
 * 
 * @param s char * | puntero a la cadena
 * @param delimiter char | caracter delimitador
 * @param new_str char ** | array bidimensional
 * @return char** | devolvemos new_str
 */
static char	**split_loop(const char *s, char delimiter, char **new_str)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s != '\0')
	{
		while (*s == delimiter && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		word_len = word_length(s, delimiter);
		new_str[i] = (char *)malloc((word_len + 1) * sizeof(char));
		if (!new_str[i])
		{
			ft_free_split(new_str, i);
			return (NULL);
		}
		ft_strlcpy(new_str[i], s, word_len + 1);
		s += word_len;
		i++;
	}
	new_str[i] = NULL;
	return (new_str);
}

/**
 * @brief 
 * Asigno memoria al arreglo con la cantidad de palabras + 1 para NULL
 * si no se produce devuelvo NULL o si la cadena que me pasan es NULL
 * devuelvo NULL, luego al arreglo le asigno lo que me devuelve la funcion
 * split_loop si esta me ha devuelto NULL libero todas las reservas de memoria
 * 
 * @param s const char * | puntero a la cadena
 * @param delimiter char | caracter delimitador
 * @return char** | el arreglo nuevo con las palabras
 */
char	**ft_split(const char *s, char delimiter)
{
	char	**new_str;

	new_str = (char **)malloc((count_words(s, delimiter) + 1) * sizeof(char *));
	if (!new_str || !s)
		return (NULL);
	new_str = split_loop(s, delimiter, new_str);
	if (!new_str)
		return (ft_free_split(new_str, count_words(s, delimiter)), NULL);
	return (new_str);
}
