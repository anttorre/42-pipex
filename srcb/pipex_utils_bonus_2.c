/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:05:56 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:36 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exec(t_data *data, char **argv, int argc)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		msg_err("Pipe");
	pid = fork();
	if (pid == -1)
		msg_err("Fork");
	if (pid == 0)
	{
		close(fd[1])
		d->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (dup2() == -1)
			msg_err("Command dup");
		if (dup2() == -1)
			msg_err("Command dup");
			
		close(d->file2);
	}
	
}
