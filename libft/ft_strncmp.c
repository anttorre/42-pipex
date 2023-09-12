/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:24:35 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:05:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Creo variables en las que almaceno las cadenas 's1' y 's2'
 * haciendoles un casting, despues en el bucle while itero sobre
 * la cadena siempre que 'i' sea menor que 'n', que no contengan un caracter
 * nulo y que ademas sean iguales los caracteres, si 'i' es igual a 'n' 
 * significa que no encontro diferencias y retorna 0, de lo contrario
 * devuelve la resta en unsigned char de los caracteres
 * 
 * @param s1 const char * | puntero a una cadena
 * @param s2 const char * | puntero a una cadena
 * @param n size_t | cantidad de bytes a comparar
 * @return int | 0 si son iguales, < 0 si s2 es mayor o > 0 si s1 es mayor
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*st1;
	char	*st2;

	i = 0;
	st1 = (char *)s1;
	st2 = (char *)s2;
	while (i < n && st1[i] != '\0' && st2[i] != '\0' && st1[i] == st2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}
/**
 * @brief
 * Version diferente de la anterior, comprueba que 'i' sea menor que 'n'
 * y que ademas una de las dos cadenas sean distintas de nulo
 * si alguna de las dos tiene un caracter nulo en su primera posicion
 * y la otra no lo tiene entra en la condicion y compara que sean
 * distintos caracteres si es asi retorna la diferencia en unsigned char
 * si no aumenta la 'i' y mueve los punteros para comprobar cada caracter
 * si no encuentra diferencias devuelve 0
 * 
 * @param s1 const char * | puntero a una cadena
 * @param s2 const char * | puntero a una cadena
 * @param n size_t | cantidad de bytes a comparar
 * @return int | 0 si son iguales, < 0 si s2 es mayor o > 0 si s1 es mayor

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (i < n && (*st1 != '\0' || *st2 != '\0'))
	{
		if (*st1 != *st2)
			return ((unsigned char)*st1 - (unsigned char)*st2);
		i++;
		st1++;
		st2++;
	}
	return (0);
}*/