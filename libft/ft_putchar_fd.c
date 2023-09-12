/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:04:57 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 12:21:49 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Escribe por un file descriptor dado un caracter
 * 
 * @param c char | caracter a escribir
 * @param fd int | file descriptor (fichero del sistema normalmente stdout)
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
