/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:45:39 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/02 12:47:29 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	msg_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	**ft_split_quotes(char *str, char d)
{
	char	**arr;

	arr = split_loop(str, d);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}

static	int	get_paths2(t_data *d)
{
	if (access(d->p_chk1, F_OK) == 0 && access(d->p_chk1, X_OK) == 0)
	{
		d->paths[d->i] = ft_calloc(ft_strlen(d->p_chk1) + 1, 1);
		if (!d->paths[d->i])
			return (EXIT_FAILURE);
		ft_strlcpy(d->paths[d->i], d->p_chk1, ft_strlen(d->p_chk1) + 1);
	}
	else if (access(d->p_chk2, F_OK) == 0 && access(d->p_chk2, X_OK) == 0)
	{
		d->paths[d->i] = ft_calloc(ft_strlen(d->p_chk1) + 1, 1);
		if (!d->paths[d->i])
			return (EXIT_FAILURE);
		ft_strlcpy(d->paths[d->i], d->p_chk2, ft_strlen(d->p_chk2) + 1);
	}
	else
		msg_err("File");
	return (EXIT_SUCCESS);
}

int	get_paths(t_data *d, int argc)
{
	d->i = -1;
	d->path1 = ft_calloc(ft_strlen("/usr/bin/") + 1, 1);
	d->path2 = ft_calloc(ft_strlen("/bin/") + 1, 1);
	d->paths = ft_calloc(argc - 2, sizeof(char *));
	if (!d->path1 || !d->path2 || !d->paths)
		return (ft_putendl_fd("Err: No memory allocated", 2), EXIT_FAILURE);
	ft_strlcpy(d->path1, "/usr/bin/", ft_strlen("/usr/bin/") + 1);
	ft_strlcpy(d->path2, "/bin/", ft_strlen("/bin/") + 1);
	while (d->cmds[++d->i])
	{
		free(d->p_chk1);
		free(d->p_chk2);
		d->p_chk1 = ft_strjoin(d->path1, d->cmds[d->i][0]);
		d->p_chk2 = ft_strjoin(d->path2, d->cmds[d->i][0]);
		if (!d->p_chk1 || !d->p_chk2)
			return (ft_putendl_fd("Err: No memory allocated", 2), EXIT_FAILURE);
		if (get_paths2(d) == EXIT_FAILURE)
			return (strerror(errno), EXIT_FAILURE);
	}
	return (d->paths[d->i] = NULL, EXIT_SUCCESS);
}

void	ft_exec(t_data *d)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		msg_err("Pipe");
	pid = fork();
	if (pid == -1)
		msg_err("Fork");
	if (pid == 0)
		child(fd, d);
	else
	{
		close(fd[0]);
		if (dup2(d->file1, STDIN_FILENO) == -1)
			msg_err("Command dup2");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			msg_err("Command dup2");
		close(d->file1);
		if (execve(d->paths[0], d->cmds[0], NULL) == -1)
			msg_err("Command");
		waitpid(pid, NULL, 0);
	}
}
