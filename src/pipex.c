/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/11 15:41:39 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	//atexit(ft_leaks);
	if (argc != 5 && argv != NULL)
		return (ft_putstr_fd("Error: argumentos no válidos\n", 2), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_struct(data);
	if (save_arguments(data, argv, argc) == EXIT_FAILURE)
		return (free_all(data, argc - 3), EXIT_FAILURE);
	int i = -1;
	while (data->cmds[++i])
	{
		int j = 0;
		while (data->cmds[i][j])
		{
				ft_printf("%s", data->cmds[i][j++]);
		}
		ft_printf("\n");
	}
	ft_printf("%s\n%s\n", data->file1, data->file2);
/* 	char *args[4];
	int fd = open("example.txt", O_WRONLY | O_CREAT, 0755);

	args[0] = "ls";
	args[1] = "-l";
	args[2] = "-a";
	args[3] = NULL;
	dup2(fd, STDOUT_FILENO);
	execve("/bin/ls", args, NULL); */
	return (free_all(data, argc - 3), EXIT_SUCCESS);
}
