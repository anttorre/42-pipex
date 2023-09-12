/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:59:46 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:58:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * obtengo el final de mi puntero con la longitud de la cadena,
 * mientras que el inicio de mi puntero sea mas pequeño o igual
 * que el final compruebo si es igual que el caracter y si lo es
 * devuelvo el puntero 's'
 * 
 * @param str char * | puntero a una cadena
 * @param c char | caracter a buscar
 * @return char* - puntero a la cadena donde encontro la primera coincidencia,
 * o NULL
 */
char	*ft_strchr(const char *str, int c)
{
	char	*s;
	size_t	s_length;
	char	*str_end;

	s = (char *)str;
	s_length = ft_strlen(s);
	str_end = s + s_length;
	while (s <= str_end)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}
/*
#include <stdio.h>

int main (void)
{
	char	*s;

	s = "H\0l\0";
	
	printf("%p", ft_strchr(s, '\0'));
}
*/