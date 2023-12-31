/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:56:57 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/26 14:27:13 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_data *data)
{
	data->paths = NULL;
	data->path1 = NULL;
	data->path2 = NULL;
	data->p_chk1 = NULL;
	data->p_chk2 = NULL;
	data->cmds = NULL;
	data->file1 = 0;
	data->file2 = 0;
	data->i = 0;
	data->j = 0;
}
