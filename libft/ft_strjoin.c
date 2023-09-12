/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:41:12 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 13:08:57 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * Une dos cadenas, reservo memoria con el tamañao de s1 y s2
 * primero copio en result con ft_strlcpy y luego con ft_strlcat
 * concateno la cadena s2
 * 
 * @param s1 const char * | puntero a una cadena
 * @param s2 const char * | puntero a una cadena
 * @return char* | la concatenacion de ambas cadenas
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = (char *)malloc(s1_length + s2_length + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_length + 1);
	ft_strlcat(result, s2, s1_length + s2_length + 1);
	return (result);
}
