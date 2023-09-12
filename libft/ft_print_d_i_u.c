/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:53:30 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/02 18:39:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_negative(long long int *n, t_flags **f)
{
	int	result;

	result = 0;
	if (*n < 0)
	{
		reinitialize_flags(f);
		result += ft_putchar('-');
		if (result == -1)
			return (-1);
		*n = -*n;
	}
	return (result);
}

int	ft_putnbr(long long int n, t_flags *f)
{
	int		result;
	char	c;

	result = 0;
	result += is_negative(&n, &f);
	if (result == -1)
		return (-1);
	if (n > 9)
	{
		result += ft_putnbr(n / 10, f);
		if (result == -1)
			return (-1);
	}
	c = n % 10 + '0';
	result += write_plus_space(f);
	if (result == -1)
		return (-1);
	result += ft_putchar(c);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putunbr(unsigned long long int n)
{
	int		result;
	char	c;

	result = 0;
	if (n > 9)
	{
		result += ft_putunbr(n / 10);
		if (result == -1)
			return (-1);
	}
	c = n % 10 + '0';
	result += ft_putchar(c);
	if (result == -1)
		return (-1);
	return (result);
}
