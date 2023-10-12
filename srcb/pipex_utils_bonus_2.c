/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:56 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 13:09:24 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exec(t_data *d, char **argv, int argc)
{
	int		fd[2];
	pid_t	pid;

	if (d->here_doc)
		here_doc(d, argv);
	else
	{
		d->file1 = open(argv[1], O_RDONLY);
		d->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (dup2(d->file1, STDIN_FILENO) == -1)
		msg_err("Child Command", d->here_doc);
	d->i = -1;
	while (d->cmds[++d->i])
	{
		if (pipe(fd) == -1)
			msg_err("Pipe", d->here_doc);
		pid = fork();
		if (pid == -1)
			msg_err("Fork", d->here_doc);
		if (pid == 0)
		{
			if (d->cmds[d->i + 1] == NULL)
			{
				if (dup2(d->file2, STDOUT_FILENO) == -1)
					msg_err("Child Command", d->here_doc);
				if (execve(d->paths[d->i], d->cmds[d->i], NULL) == -1)
					msg_err("Child Command Execution", d->here_doc);
				break ;
			}
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				msg_err("Child Command", d->here_doc);
			if (execve(d->paths[d->i], d->cmds[d->i], NULL) == -1)
				msg_err("Child Command Execution", d->here_doc);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
		}
	}
}
