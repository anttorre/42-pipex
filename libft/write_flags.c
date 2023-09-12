/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:04:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/02 19:14:20 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_space(t_flags *f)
{
	if (f->space)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		f->space = 0;
		return (1);
	}
	return (0);
}

int	write_plus(t_flags *f)
{
	if (f->plus)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
		f->plus = 0;
		f->space = 0;
		return (1);
	}
	return (0);
}

int	write_sharp(t_flags *f, char *s)
{
	if (f->sharp)
	{
		if (write(1, s, 2) == -1)
			return (-1);
		f->plus = 0;
		f->space = 0;
		f->sharp = 0;
		return (2);
	}
	return (0);
}

int	write_plus_space(t_flags *f)
{
	int	result;

	result = 0;
	if (f->plus)
	{
		result += write_plus(f);
		if (result == -1)
			return (-1);
	}
	if (f->space)
	{
		result += write_space(f);
		if (result == -1)
			return (-1);
	}
	return (result);
}
