/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:45:39 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/05 16:00:33 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	msg_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error(char *error)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
}

char	**ft_split_quotes(char *str, char d)
{
	char	**arr;

	arr = split_loop(str, d);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}

int	get_env_paths(char **env, t_data *d)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	*env += 5;
	d->env_paths = ft_split_quotes(*env, ':');
	if (!d->env_paths)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_paths(t_data *d)
{
	char	*tmp;

	d->i = -1;
	d->paths = ft_calloc(d->n_cmd + 1, sizeof(char *));
	while (d->cmds[++d->i])
	{
		d->j = -1;
		while (d->env_paths[++d->j])
		{
			tmp = ft_strjoin(d->env_paths[d->j], "/");
			d->pchk = ft_strjoin(tmp, d->cmds[d->i][0]);
			if (!tmp || !d->pchk)
				return (error("Path check not saved."), EXIT_FAILURE);
			free(tmp);
			if (access(d->pchk, F_OK) == 0 && access(d->pchk, X_OK) == 0)
			{
				d->paths[++d->k] = d->pchk;
				d->pchk = NULL;
				break ;
			}
			free(d->pchk);
		}
	}
	return (d->paths[++d->k] = NULL, EXIT_SUCCESS);
}