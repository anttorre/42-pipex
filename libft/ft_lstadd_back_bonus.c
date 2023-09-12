/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:16:17 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:38:31 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * creamos un puntero a una lista auxiliar para poder recorrer la lista
 * si el nuevo nodo a añadir al final de la lista es NULL simplemente no
 * hace nada, si la lista nuestra real es NULL el contenido de nuestra lista
 * lo ponemos a new si no recorremos el nodo auxiliar mientras que no sea NULL
 * y añadimo new al ultimo nodo
 * 
 * @param lst t_list ** | direccion de memoria de nuestra lista
 * @param new t_list * | nuevo nodo a añadir al final de la lista
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first_node;

	first_node = *lst;
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (first_node->next != NULL)
		first_node = first_node->next;
	first_node->next = new;
}
