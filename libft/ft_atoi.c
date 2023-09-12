/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:05:00 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/05 16:44:53 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Recorro la cadena saltando los espacios y tabulaciones, luego
 * compruebo si el caracter es '-' o '+' si es negativo el signo
 * se pone a negativo, despues comprobamos que los caracteres en
 * la cadena esten entre '0' y '9' y en la variable num almacenamos
 * el numero (num = 0 * 10 + (49 - 48); esto da como resultado 1 en
 * entero) y finalmente devolvemos el numero multiplicado por el
 * signo.
 * 
 * @param str const char * | la string a transformar en entero
 * @return int -  la string transformada a entero
 */
int	ft_atoi(const char *str)
{
	int				num;
	unsigned int	i;
	int				sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}
