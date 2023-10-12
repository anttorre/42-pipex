/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:56:57 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 15:24:59 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	init_struct(t_data *data)
{
	data->here_doc = 0;
	data->paths = NULL;
	data->env_paths = NULL;
	data->cmds = NULL;
	data->pchk = NULL;
	data->file1 = 0;
	data->file2 = 0;
	data->i = 0;
	data->j = 0;
	data->k = -1;
	data->n_cmd = 0;
	data->line = NULL;
}
