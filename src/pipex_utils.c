/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:45:39 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/20 12:23:18 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_split_quotes(char *str, char d)
{
	char	**arr;

	arr = split_loop(str, d);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}

static void	free_paths(char	*p_check1, char	*p_check2, char	*path1, char *path2)
{
	free(p_check1);
	free(p_check2);
	free(path1);
	free(path2);
}

int	get_paths(t_data *d, int argc)
{
	char	*p_check1;
	char	*p_check2;
	char	*path1;
	char	*path2;

	d->i = -1;
	path1 = ft_calloc(ft_strlen("/usr/bin/") + 1, 1);
	path2 = ft_calloc(ft_strlen("/bin/") + 1, 1);
	d->paths = ft_calloc(argc - 2, sizeof(char *));
	if (!path1 || !path2 || !d->paths)
		return (free(path1), free(path2), EXIT_FAILURE);
	ft_strlcpy(path1, "/usr/bin/", ft_strlen("/usr/bin/") + 1);
	ft_strlcpy(path2, "/bin/", ft_strlen("/bin/") + 1);
	p_check1 = NULL;
	p_check2 = NULL;
	while (d->cmds[++d->i])
	{
		free(p_check1);
		free(p_check2);
		p_check1 = ft_strjoin(path1, d->cmds[d->i][0]);
		p_check2 = ft_strjoin(path2, d->cmds[d->i][0]);
		if (!p_check1 || !p_check2)
			return (free_paths(p_check1, p_check2, path1, path2), EXIT_FAILURE);
		if (access(p_check1, F_OK) == 0 && access(p_check1, X_OK) == 0)
		{
			d->paths[d->i] = ft_calloc(ft_strlen(p_check1) + 1, 1);
			if (!d->paths[d->i])
				return (free_paths(p_check1, p_check2, path1, path2), 1);
			ft_strlcpy(d->paths[d->i], p_check1, ft_strlen(p_check1) + 1);
		}
		else if (access(p_check2, F_OK) == 0 && access(p_check2, X_OK) == 0)
		{
			d->paths[d->i] = ft_calloc(ft_strlen(p_check1) + 1, 1);
			if (!d->paths[d->i])
				return (free_paths(p_check1, p_check2, path1, path2), 1);
			ft_strlcpy(d->paths[d->i], p_check2, ft_strlen(p_check2) + 1);
		}
		else
			return (free_paths(p_check1, p_check2, path1, path2), EXIT_FAILURE);
	}
	return (d->paths[d->i] = NULL, free_paths(p_check1, p_check2, path1, path2), EXIT_SUCCESS);
}
