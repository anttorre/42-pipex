/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:56 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 16:49:48 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_father(pid_t pid, int *fd)
{
	waitpid(pid, NULL, 0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}

static void	ft_check_here_doc(t_data *d, char **argv, int argc)
{
	if (d->here_doc)
		here_doc(d, argv);
	else
	{
		d->file1 = open(argv[1], O_RDONLY);
		d->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}

static void	continue_child(t_data *d)
{
	close(d->fd[0]);
	if (dup2(d->fd[1], STDOUT_FILENO) == -1)
		msg_err("Child Command", d->here_doc);
	if (execve(d->paths[d->i], d->cmds[d->i], NULL) == -1)
		msg_err("Child Command Execution", d->here_doc);
}

static void	create_pipe(t_data *d)
{
	if (pipe(d->fd) == -1)
		msg_err("Pipe", d->here_doc);
}

void	ft_exec(t_data *d, char **argv, int argc)
{
	ft_check_here_doc(d, argv, argc);
	if (dup2(d->file1, STDIN_FILENO) == -1)
		msg_err("Child Command", d->here_doc);
	d->i = -1;
	while (d->cmds[++d->i])
	{
		create_pipe(d);
		d->pid = fork();
		if (d->pid == -1)
			msg_err("Fork", d->here_doc);
		if (d->pid == 0)
		{
			if (d->cmds[d->i + 1] == NULL)
			{
				if (dup2(d->file2, STDOUT_FILENO) == -1)
					msg_err("Child Command", d->here_doc);
				if (execve(d->paths[d->i], d->cmds[d->i], NULL) == -1)
					msg_err("Child Command Execution", d->here_doc);
				break ;
			}
			continue_child(d);
		}
		else
			ft_father(d->pid, d->fd);
	}
}
