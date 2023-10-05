/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/02 12:51:13 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(int *fd, t_data *d)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		msg_err("Command dup2");
	if (dup2(d->file2, STDOUT_FILENO) == -1)
		msg_err("Command dup2");
	close(d->file2);
	if (execve(d->paths[1], d->cmds[1], NULL) == -1)
		msg_err("Command");
}

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argv != NULL)
		return (ft_putendl_fd("Error: invalid arguments", 2), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_struct(data);
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 == -1)
		msg_err("File");
	data->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file2 == -1)
		msg_err("File");
	if (save_arguments(data, argv, argc) == EXIT_FAILURE)
		return (ft_putendl_fd("Error: args not saved", 2), 
			free_all(data), EXIT_FAILURE);
	if (get_paths(data, argc) == EXIT_FAILURE)
		return (free_all(data), EXIT_FAILURE);
	ft_exec(data);
	return (free_all(data), EXIT_SUCCESS);
}
