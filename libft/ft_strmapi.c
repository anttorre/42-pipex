/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:54:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 15:18:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	uppercase(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
*/

/**
 * @brief 
 * reserva memoria para la nueva string, mientras que la cadena
 * no sea nula '\0' copia en la nueva cadena el caracter pasandole
 * una funcion a cada caracter y terminandola en '\0'
 * 
 * @param s const char * | puntero a la cadena
 * @param f char | funciona que devuelve el caracter modificado
 * @return char* | la nueva cadena transformada
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_length;
	char	*new_string;
	size_t	i;

	s_length = ft_strlen(s);
	new_string = malloc(s_length * sizeof(char) + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hola PepiTO";
	char	*str = ft_strmapi(src, uppercase);

	printf("Nueva string en mayusculas: %s\n", str);
	return (0);
}
*/