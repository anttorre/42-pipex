/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/02 12:54:21 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	void	free_paths(t_data *d)
{
	free(d->p_chk1);
	free(d->p_chk2);
	free(d->path1);
	free(d->path2);
}

void	free_all(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->cmds[++i] != NULL)
	{
		j = 0;
		while (data->cmds[i][j])
			free(data->cmds[i][j++]);
		free(data->cmds[i]);
	}
	free(data->cmds);
	i = -1;
	while (data->paths[++i])
		free(data->paths[i]);
	free(data->paths);
	free_paths(data);
	free(data);
}

int	save_arguments(t_data *d, char **argv, int argc)
{
	d->i = 1;
	d->cmds = ft_calloc(argc - 2, sizeof(char **));
	if (!d->cmds)
		return (EXIT_FAILURE);
	while (++d->i < argc - 1)
	{
		d->cmds[d->j] = ft_split_quotes(argv[d->i], ' ');
		if (!d->cmds[d->j++])
			return (EXIT_FAILURE);
	}
	d->cmds[d->j] = NULL;
	return (EXIT_SUCCESS);
}
