/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:15:35 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/14 16:32:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * si no hay src o no hay dst (nulas) deuelve NULL,
 * luego se comprueba que hay espacio en el destino
 * es decir que el dstsize sea mayor que 0 si es asi entra
 * en el bucle que mientras el caracter que copiamos sea distinto
 * de nulo y 'i' sea menor que el tamaño de destino - 1 para reservar
 * un nulo al final de la cadena comienza a copiar y si no se cumple
 * es por que solo habia 1 espacio y este ha sido usado para el nulo
 * 
 * @param dst char * | puntero al que copiar
 * @param src const char * | puntero desde el que copiar
 * @param dstsize size_t | tamaño del buffer destino
 * @return size_t | la cantidad de caracteres del origen que se deberian copiar
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			srclength;
	unsigned int	i;

	srclength = ft_strlen(src);
	if (!src || !dst)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclength);
}
/*
#include <stdio.h>
int main()
{
	char dst[10] = "";
	char src[10] = "";

	printf("%zu",ft_strlcpy(dst, src, 10));
}
*/