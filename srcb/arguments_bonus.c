/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:16:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/04 13:16:09 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	save_args(t_data *d, char **argv, int argc)
{
	while (++d->i < argc - 1)
	{
		d->cmds[d->j] = ft_split_quotes(argv[d->i], ' ');
		if (!d->cmds[d->j++])
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	save_arguments(t_data *d, char **argv, int argc)
{
	if (!d->here_doc)
	{
		d->n_cmd = argc - 2;
		d->i = 1;
	}
	else
	{
		d->n_cmd = argc - 3;
		d->i = 2;
	}
	d->cmds = ft_calloc(d->n_cmd, sizeof(char **));
	if (!d->cmds)
		return (EXIT_FAILURE);
	if (save_args(d, argv, argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	d->cmds[d->j] = NULL;
	return (EXIT_SUCCESS);
}
