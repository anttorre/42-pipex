/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:41:10 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:24:40 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Se comrpueba que el tamaño de la cadena sea mas pequeño que la suma de
 * len y start para modificar el len restandole s_length - start
 * si el start es mayor que el tamaño de mi cadena len es 0
 * luego hace una reserva segun el tamaño de la subcadena
 * y comienza a copiar desde el inicio que le dimos y lo acaba con '\0'
 * 
 * @param s const char * | cadena donde hacer una subcadena
 * @param start unsigned int | desde donde empieza a sustraer 
 * @param len size_t | cantidad de caracteres a sustraer
 * @return char* | la subcadena
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			j;
	size_t			s_length;

	i = start;
	j = 0;
	s_length = ft_strlen(s);
	if (s_length < len + start)
		len = s_length - start;
	if (start > s_length)
		len = 0;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr || !s)
		return (NULL);
	while (j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
