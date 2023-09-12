/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:24:48 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/28 13:09:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX "0123456789abcdef"
# define HEXUPPER "0123456789ABCDEF"
# define SHARP "0x"
# define SHARPUPPER "0X"
# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	space;
	int	plus;
	int	sharp;
}		t_flags;

int		ft_printf(char const *s, ...);

int		ft_putchar(char c);

int		ft_putstr(char *s);

int		ft_putnbr(long long int n, t_flags *f);

int		ft_putunbr(unsigned long long int n);

int		ft_hexa(unsigned long long n, t_flags *f);

int		ft_hexaupper(unsigned long long n, t_flags *f);

int		ft_ptr(unsigned long long n, t_flags *f);

void	check_flags(char const **s, t_flags *f);

int		write_space(t_flags *f);

int		write_plus(t_flags *f);

int		write_sharp(t_flags *f, char *s);

int		write_plus_space(t_flags *f);

void	reinitialize_flags(t_flags **f);

t_flags	*initialize_flags(t_flags *f);

#endif