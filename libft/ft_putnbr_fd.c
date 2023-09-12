/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:28:29 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 12:25:33 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Escrbe en un file descriptor un numero contemplando el
 * INT_MAX y INT_MIN hace uso de ft_putchar_fd y ft_putstr_fd
 * 
 * @param n int | numero a escribir
 * @param fd int | file descriptor (fichero del sistema normalmente stdout)
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	aux;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		aux = n + '0';
		ft_putchar_fd(aux, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
