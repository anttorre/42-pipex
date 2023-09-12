/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:21:41 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 16:49:38 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Reservamos memoria con malloc (num_elems * size) si
 * es NULL la reserva, devolvemos NULL si no, colocamos a '\0'
 * toda la memoria reservada y devolvemos el puntero genérico
 * 
 * @param num_elements size_t | cantidad de elementos
 * @param size size_t | el tamaño del tipo de dato
 * @return void* - puntero generico o NULL
 */
void	*ft_calloc(size_t num_elements, size_t size)
{
	void	*memory_allocated;

	memory_allocated = malloc(num_elements * size);
	if (memory_allocated == NULL)
		return (NULL);
	ft_bzero(memory_allocated, (num_elements * size));
	return (memory_allocated);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	str = (char *)calloc(0, sizeof(char));
	strlcpy(str, "Holae12346789*", 150);
	printf("LIBC calloc: '%s'\n", str);
	free(str);
	return (0);
}
*/