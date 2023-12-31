/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:52:57 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 13:10:29 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_struct(data);
	if (argc < check_here_doc(argv, data))
		return (error("few arguments."), free_all(data), EXIT_FAILURE);
	if (save_arguments(data, argv, argc))
		return (error("arguments not saved."), free_all(data), EXIT_FAILURE);
	if (get_env_paths(env, data))
		return (error("env paths not saved."), free_all(data), EXIT_FAILURE);
	if (get_paths(data))
		return (error("Path error."), free_all(data), EXIT_FAILURE);
	ft_exec(data, argv, argc);
	return (free_all(data), EXIT_SUCCESS);
}
