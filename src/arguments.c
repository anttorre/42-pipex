/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/11 15:43:26 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <signal.h>

void	free_all(t_data *data, int len)
{
	int		i;
	int		j;

	(void) len;
	i = -1;
	if (data->cmds != NULL)
	{
		while (data->cmds[++i] != NULL)
		{
			j = 0;
			while (data->cmds[i][j])
				free(data->cmds[i][j++]);
			free(data->cmds[i]);
		}
		free(data->cmds);
	}
	if (data->file1 != NULL)
		free(data->file1);
	if (data->file2 != NULL)
		free(data->file2);
	if (data != NULL)
		free(data);
}

/* static void	free_part_cmd(char **cmd, int index)
{
	if (cmd != NULL)
	{
		while (--index >= 0)
			free(cmd[index]);
		free(cmd);
	}
} */

/* int	save_arguments(t_data *d, char **argv, int argc)
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
	d->cmd = ft_calloc(argc - 3, sizeof(char *));
	if (!d->cmd)
		return (EXIT_FAILURE);
	while (++d->i < argc - 1)
	{
		d->cmd[++d->j] = ft_calloc(ft_strlen(argv[d->i]) + 1, sizeof(char));
		if (!d->cmd[d->j])
			return (free_part_cmd(d->cmd, d->j), EXIT_FAILURE);
		ft_strlcpy(d->cmd[d->j], argv[d->i], ft_strlen(argv[d->i]) + 1);
	}
	return (EXIT_SUCCESS);
} */

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
		d->cmds[d->j] = ft_split(argv[d->i], ' ');
		if (!d->cmds[d->j++])
			return (EXIT_FAILURE);
	}
	d->cmds[d->j] = NULL;
	return (EXIT_SUCCESS);
}

//file1 cmd1 cmd2 cmd3 cmd4 cm5 file2