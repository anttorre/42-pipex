/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:00:46 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 16:46:09 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Cuenta cuantos digitos hay en un número
 * 
 * @param n Numero
 * @return int - cantidad de digitos
 */
static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/**
 * @brief 
 * Convierte un numero en cadena, obtengo la cantidad de
 * digitos con nbrlen, hago una reserva de esa cantidad +1
 * para el '\0', si es negativo en la primera posicion
 * guardo '-' y cambio el numero a positivo, en la ultima 
 * posicion pongo '\0' y resto 1 al tamaño luego mientras el
 * numero no sea 0 guardo en num_length el caracter, divido 
 * entre 10 y resto 1 al tamaño.
 * 
 * @param n int | numero a transformar
 * @return char* - puntero a la cadena creada o NULL si falla
 */
char	*ft_itoa(int n)
{
	char	*str;
	size_t	num_length;

	num_length = ft_nbrlen(n);
	str = (char *)malloc(num_length + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", num_length + 1);
	if (n == 0)
		ft_strlcpy(str, "0", num_length + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[num_length] = '\0';
	num_length--;
	while (n > 0)
	{
		str[num_length] = n % 10 + '0';
		n /= 10;
		num_length--;
	}
	return (str);
}
