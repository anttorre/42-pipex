/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:22 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/19 15:11:58 by anttorre         ###   ########.fr       */
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

	atexit(ft_leaks);
	if (argc != 5 && argv != NULL)
		return (ft_putendl_fd("Error: invalid arguments", 2), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_struct(data);
	if (save_arguments(data, argv, argc) == EXIT_FAILURE)
		return (ft_putendl_fd("Error: args not saved", 2), 
			free_all(data), EXIT_FAILURE);
	if (get_paths(data, argc) == EXIT_FAILURE)
		return (ft_putendl_fd("Error: invalid permissions", 2), free_all(data), EXIT_FAILURE);
	/* BORRAR */
	int i = -1;
	while (data->paths[++i])
	{
		int j = 0;
		while (data->cmds[i][j])
			ft_printf("%s ", data->cmds[i][j++]);
		ft_printf("\n");
		ft_printf("%s ", data->paths[i]);
		ft_printf("\n");
	}
	ft_printf("%s\n%s\n", data->file1, data->file2);
	/* HASTA AQUI */
	return (free_all(data), EXIT_SUCCESS);
}
