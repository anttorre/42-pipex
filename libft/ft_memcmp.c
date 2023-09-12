/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:19:43 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 17:06:29 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Mientras que 'i' sea menor que la cantidad de bytes comprueba si no
 * son identicos y devuelve la resta en unsigned char de los caracteres
 * y se avanzan los punteros para comprobar el resto.
 * 
 * @param s1 const void * | puntero a zona de memoria
 * @param s2 const void * | puntero a zona de memoria
 * @param n size_t | cantidad de bytes a comprobar
 * @return int - 0 si son iguales, < 0 si s2 es mayor o > 0 si s1 es mayor
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (i++ < n)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	return (0);
}
