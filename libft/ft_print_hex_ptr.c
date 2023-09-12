/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:02:10 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/02 19:11:52 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long long n, t_flags *f)
{
	int	result;

	result = 0;
	if (f->sharp && n != 0)
	{
		result += write_sharp(f, SHARP);
		if (result == -1)
			return (-1);
	}
	if (n > 15)
	{
		result += ft_hexa(n / 16, f);
		if (result == -1)
			return (-1);
	}
	result += ft_putchar(HEX[n % 16]);
	return (result);
}

int	ft_hexaupper(unsigned long long n, t_flags *f)
{
	int	result;

	result = 0;
	if (f->sharp && n != 0)
	{
		result += write_sharp(f, SHARPUPPER);
		if (result == -1)
			return (-1);
	}
	if (n > 15)
	{
		result += ft_hexaupper(n / 16, f);
		if (result == -1)
			return (-1);
	}
	result += ft_putchar(HEXUPPER[n % 16]);
	return (result);
}

int	ft_ptr(unsigned long long n, t_flags *f)
{
	int	result;

	result = 0;
	result += write(1, "0x", 2);
	if (result == -1)
		return (-1);
	result += ft_hexa(n, f);
	if (result == -1)
		return (-1);
	return (result);
}
