/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:24:40 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 15:08:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * primero se comprueba si dst y src son nulos,
 * luego se comprueba si el tamaño de dst (caracteres) es mayor/igual que el size
 * para comprobar que haya espacio en el buffer de destino
 * luego se comprueba que el primer caracter de source no sea nulo
 * y ademas que la cantidad de caracteres que se añaden a partir del tamaño
 * que ya contenia el destino sea menor que el size - 1 para reservar un NULO
 * al final de la cadena por ultimo añade un caracter nulo para asegurar el
 * final de la cadena
 * 
 * @param dst buffer de destino
 * @param src buffer con la cadena a concatenar
 * @param size tamaño del buffer destino
 * @return size_t retorna el tamaño total copiado de dst y src
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	if (!dst && !src)
		return (0);
	if (dst_length >= size)
		return (src_length + size);
	while (src[i] != '\0' && (dst_length + i) < (size - 1))
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

/*
int main(void)
{
    char dst[10] = "Prueba ";
    char src[10] = "Hola mundo";
    
    //printf("LIBC strlcat: %lu\n", strlcat(dst, 
	"lorem ipsum dolor sit amet", 15));
	printf("ft_strlcat: %lu\n",ft_strlcat(dst, src, 15));
    printf("'%s'\n", dst);
    return 0;
}*/
