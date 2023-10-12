/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:53:55 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/12 14:58:59 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_data
{
	int		file1;
	int		file2;
	char	***cmds;
	char	**paths;
	char	**env_paths;
	char	*pchk;
	int		here_doc;
	char 	*line;
	int		n_cmd;
	int		i;
	int		j;
	int		k;
}			t_data;

void		init_struct(t_data *data);
void		free_all(t_data *data);
int			save_arguments(t_data *d, char **argv, int argc);
char		**ft_split_quotes(char *str, char d);
char		**split_loop(char *str, char d);
int			word_length(char *str, char d, int flag, char c);
size_t		words_count(char *str, char d);
void		free_split_quotes(char **arr);
int			get_paths(t_data *d);
void		msg_err(char *str, int here_doc);
void		error(char *error);
int			check_here_doc(char **argv, t_data *data);
int			get_env_paths(char **env, t_data *d);
void		here_doc(t_data *d, char **argv);
void		ft_exec(t_data *d, char **argv, int argc);

#endif