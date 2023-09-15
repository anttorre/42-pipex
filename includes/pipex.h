/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/09/14 16:35:10 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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
size_t		ft_strlcpy_pipex(char *dst, char *src, size_t dstsize);
char		**ft_split_quotes(char *str, char d);
char		**split_loop(char *str, char d);
int			word_length(char *str, char d, int flag, char c);
size_t		words_count(char *str, char d);
void		free_split_quotes(char **arr);

#endif