/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:32:28 by anttorre          #+#    #+#             */
/*   Updated: 2023/08/07 14:03:24 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief
 * borramos el contenido del nodo y liberamos el nodo
 * 
 * @param lst t_list * | puntero al nodo
 * @param del void | puntero a una funcion que elimina
 */
void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	del(lst->index);
	del(lst->pos);
	del(lst->target_pos);
	del(lst->cost_a);
	del(lst->cost_b);
	free(lst);
	lst = NULL;
}
