/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:22:26 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:40:32 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * si el nuevo nodo es NULL nos salimos, si lst es NULL igualamos lst
 * a new y nos salimos si no, new-next equivale al primero nodo de lst
 * y lst equivale a new
 * 
 * @param lst t_list ** | direccion de memoria de nuestra lista
 * @param new t_list * | nuevo nodo a añadir al principio de la lista
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
