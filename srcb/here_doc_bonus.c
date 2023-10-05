/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:18:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/03 15:16:05 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_here_doc(char **argv, t_data *data)
{
	if (argv && !ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")))
	{
		data->here_doc = 1;
		return (6);
	}
	return (5);
}
