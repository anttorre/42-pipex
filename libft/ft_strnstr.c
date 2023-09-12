/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:27:37 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:59:52 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Si la cadena to_find es vacia devuelve la cadena donde 
 * iba a buscar la palabra * luego mientras que mi 'i' sea menor
 * que la cantidad de caracteres a buscar 'len' * y la cadena no 
 * sea nula entra al bucle y comprueba que si el caracter es igual 
 * que * el que busca y 'i' + 'j' sean menor que el tamaño comprueba
 * si el siguiente * caracter de 'to_find' es nulo y devuelve la 
 * posicion donde encontro la misma cadena
 * 
 * @param haystack const char * | cadena donde buscar
 * @param needle const char * | cadena a buscar
 * @param len size_t | cantidad de caracteres a buscar
 * @return char* | puntero a donde empieza la coincidencia
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	i = 0;
	str = (char *)haystack;
	to_find = (char *)needle;
	if (*to_find == '\0')
		return (str);
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*haystack;
	char	*needle;

	haystack = "The brown pepe";
	needle = NULL;
	printf("%s", ft_strnstr(haystack, needle, 15));
	return (0);
}
*/