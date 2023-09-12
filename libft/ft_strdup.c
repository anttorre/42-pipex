/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:36:56 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 12:55:49 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * obtengo el tamaño de s1 con strlen y le sumo 1 para el
 * caracter nulo de fin de cadena, en la cadena s2 reservo memoria
 * con la cantidad de bytes del tamaño de la s1 si no puede reservar
 * retorna null de lo contrario entra al bucle y comienza a copiar
 * desde 'i' hasta menos del 'size' y devuelve el puntero a la
 * cadena duplicada.
 * 
 * @param s1 const char * | cadena a duplicar
 * @return char* | puntero a la cadena duplicada
 */
char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = malloc(size);
	i = 0;
	if (!s2)
		return (NULL);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n", ft_strdup("peruca"));
}*/