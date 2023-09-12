/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:24:30 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 12:20:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief
 * casting a b en unsigned char para poder trabajar con void *
 * mientas que 'i' sea menor que 'len' copiamos el caracter 'c'
 * 
 * @param b void * | puntero generico a una zona de memoria
 * @param c int | caracter que queremos poner en la memoria
 * @param len size_t | cantidad de bytes
 * @return void* | puntero generico a 'b'
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)b;
	while (i < len)
	{
		dst[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}
