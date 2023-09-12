/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:00:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 16:49:56 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Mientras que el indice no llegue a la cantidad de
 * tamaño en la string en la posicion 'i' colocara el
 * caracter vacío, el puntero generico hay que guardarlo
 * en una variable char * y hacerle un casting para poder
 * trabajar con el puntero void.
 * 
 * @param s void * | puntero generico
 * @param n size_t | cantidad de bytes a poner en '\0'
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
