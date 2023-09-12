/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/11 15:35:19 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	***cmds;
	int		i;
	int		j;
}			t_data;

void		init_struct(t_data *data);
void		free_all(t_data *data, int len);
int			save_arguments(t_data *d, char **argv, int argc);

#endif