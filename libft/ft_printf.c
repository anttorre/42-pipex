/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:05:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/14 15:28:54 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format1(const char **s, va_list args, t_flags *f);
static int	check_format2(const char **s, va_list args, t_flags *f);
static int	check_format3(const char **s, va_list args, t_flags *f);

static int	check_format(const char *s, va_list args, int *tl, t_flags *f)
{
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			*tl += check_format1(&s, args, f);
			if (*tl == -1)
				return (-1);
			*tl += check_format2(&s, args, f);
			if (*tl == -1)
				return (-1);
			*tl += check_format3(&s, args, f);
			if (*tl == -1)
				return (-1);
			s++;
		}
		else
		{
			*tl += ft_putchar(*s);
			if (*tl == -1)
				return (-1);
			s++;
		}
	}
	return (*tl);
}

static int	check_format1(const char **s, va_list args, t_flags *f)
{
	int	tl;

	tl = 0;
	check_flags(s, f);
	if (**s == '%')
	{
		tl += ft_putchar(**s);
		if (tl == -1)
			return (-1);
	}
	if (**s == 'c')
	{
		tl += ft_putchar(va_arg(args, int));
		if (tl == -1)
			return (-1);
	}
	if (**s == 's')
	{
		tl += ft_putstr(va_arg(args, char *));
		if (tl == -1)
			return (-1);
	}
	return (tl);
}

static int	check_format2(const char **s, va_list args, t_flags *f)
{
	int	tl;

	tl = 0;
	check_flags(s, f);
	if (**s == 'd' || **s == 'i')
	{
		tl += ft_putnbr(va_arg(args, int), f);
		if (tl == -1)
			return (-1);
	}
	if (**s == 'u')
	{
		tl += ft_putunbr(va_arg(args, unsigned int));
		if (tl == -1)
			return (-1);
	}
	return (tl);
}

static int	check_format3(char const **s, va_list args, t_flags *f)
{
	int	tl;

	tl = 0;
	if (**s == 'x' || **s == 'X')
	{
		if (**s == 'X')
		{
			tl += ft_hexaupper(va_arg(args, unsigned int), f);
			if (tl == -1)
				return (-1);
		}
		else
		{
			tl += ft_hexa(va_arg(args, unsigned int), f);
			if (tl == -1)
				return (-1);
		}
	}
	if (**s == 'p')
	{
		tl += ft_ptr(va_arg(args, unsigned long long), f);
		if (tl == -1)
			return (-1);
	}
	return (tl);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		tl;
	t_flags	*f;

	tl = 0;
	f = (t_flags *)malloc(sizeof(t_flags));
	if (!f)
		return (-1);
	f = initialize_flags(f);
	va_start(args, s);
	tl = check_format(s, args, &tl, f);
	va_end(args);
	if (tl == -1)
		return (free(f), -1);
	return (free(f), tl);
}
