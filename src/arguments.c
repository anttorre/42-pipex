/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/19 15:39:44 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <signal.h>

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
	free(data->file1);
	free(data->file2);
	i = -1;
	while (data->paths[++i])
		free(data->paths[i]);
	free(data->paths);
	free(data);
}

int	save_arguments(t_data *d, char **argv, int argc)
{
	d->file1 = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
	if (!d->file1)
		return (EXIT_FAILURE);
	ft_strlcpy(d->file1, argv[1], ft_strlen(argv[1]) + 1);
	d->file2 = ft_calloc(ft_strlen(argv[argc - 1]) + 1, sizeof(char));
	if (!d->file2)
		return (EXIT_FAILURE);
	ft_strlcpy(d->file2, argv[argc - 1], ft_strlen(argv[argc - 1]) + 1);
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

//awk -F ',' '{print $1, $3}' datos.txt