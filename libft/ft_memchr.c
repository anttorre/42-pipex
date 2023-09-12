/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:10:37 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 16:45:34 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * busca un caracter 'c' en 'n' caracteres que le pasemos
 * mientras que 'i' sea menor que la cantidad que le pasamos
 * entra al bucle y comprueba si el contenido del puntero es igual
 * al caracter que buscamos si es asi retorna un puntero generico
 * de donde se encuentra el caracter en 'str' si no suma uno en la 'i'
 * y muevo el puntero 'str' para comprobar el siguiente caracter.
 * 
 * @param s const void * | puntero a una zona en memoria
 * @param c int | caracter a buscar 
 * @param n size_t | cantidad de bytes a comprobar
 * @return void* puntero al caracter o NULL si no encuentra
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		i++;
		str++;
	}
	return (NULL);
}
