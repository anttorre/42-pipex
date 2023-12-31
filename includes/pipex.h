/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/02 12:47:17 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	int		file1;
	int		file2;
	char	***cmds;
	char	**paths;
	char	*path1;
	char	*path2;
	char	*p_chk1;
	char	*p_chk2;
	int		i;
	int		j;
}			t_data;

void		init_struct(t_data *data);
void		free_all(t_data *data);
int			save_arguments(t_data *d, char **argv, int argc);
size_t		ft_strlcpy_pipex(char *dst, char *src, size_t dstsize);
char		**ft_split_quotes(char *str, char d);
char		**split_loop(char *str, char d);
int			word_length(char *str, char d, int flag, char c);
size_t		words_count(char *str, char d);
void		free_split_quotes(char **arr);
int			get_paths(t_data *d, int argc);
void		ft_exec(t_data *d);
void		msg_err(char *str);
void		child(int *fd, t_data *d);

#endif