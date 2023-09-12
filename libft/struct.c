/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:16 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/02 18:39:55 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*initialize_flags(t_flags *f)
{
	f->space = 0;
	f->plus = 0;
	f->sharp = 0;
	return (f);
}

void	check_flags(char const **s, t_flags *f)
{
	if (**s == ' ')
	{
		f->space = 1;
		(*s)++;
	}
	if (**s == '+')
	{
		f->plus = 1;
		(*s)++;
	}
	if (**s == '#')
	{
		f->sharp = 1;
		(*s)++;
	}
}

void	reinitialize_flags(t_flags **f)
{
	(*f)->space = 0;
	(*f)->plus = 0;
	(*f)->sharp = 0;
}
