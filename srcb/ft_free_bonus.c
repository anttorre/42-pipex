/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:18:18 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 15:34:49 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	free_all_2(t_data *data);

void	free_all(t_data *data)
{
	int		i;
	int		j;

	if (data->cmds)
	{
		i = -1;
		while (data->cmds[++i] != NULL)
		{
			j = 0;
			while (data->cmds[i][j])
				free(data->cmds[i][j++]);
			free(data->cmds[i]);
		}
		free(data->cmds);
	}
	if (data->paths)
	{
		i = -1;
		while (data->paths[++i])
			free(data->paths[i]);
		free(data->paths);
	}
	free_all_2(data);
	free(data);
}

static void	free_all_2(t_data *data)
{
	int	i;

	if (data->env_paths)
	{
		i = -1;
		while (data->env_paths[++i])
			free(data->env_paths[i]);
		free(data->env_paths);
	}
	if (data->here_doc)
		unlink("here_doc.tmp");
	close(data->file1);
	close(data->file2);
	if (data->line)
		free(data->line);
}
