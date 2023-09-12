/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:27:53 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:59:00 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	uppercase(unsigned int index, char *c)
{
	if (index == 2)
		*c = 'T';
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
} */

/**
 * @brief 
 * Mientras que la cadena no sea vacia le va a pasar una
 * funcion que modificara realmente la cadena
 * 
 * @param s char * | puntero a una cadena
 * @param f void | puntero a una función
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* #include <stdio.h>
int	main(void)
{
	char	src[] = "Hola PepiTO";
	ft_striteri(src, &uppercase);

	printf("Nueva string en mayusculas: %s\n", src);
	return (0);
} */
