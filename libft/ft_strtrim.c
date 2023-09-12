/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:44:04 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/18 12:55:06 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Mientras que no sea nula la cadena y ademas encuentre
 * los caracteres en la cadena avanza el puntero del inicio
 * luego coloco en una variable  la longitud de la cadena y
 * recorro desde atras lo mismo pero esta vez con el indice
 * 
 * @param s1 char const * | puntero a la cadena
 * @param set char const * | caracteres a quitar de la cadena s1
 * @return char* | nuevo puntero a la cadena formada
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (s1 == 0 || set == 0)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i != 0 && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
