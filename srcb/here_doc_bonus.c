/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:18:03 by anttorre          #+#    #+#             */
/*   Updated: 2023/10/13 12:57:59 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_here_doc(char **argv, t_data *data)
{
	if (argv && !ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")))
	{
		data->here_doc = 1;
		return (6);
	}
	return (5);
}

void	here_doc(t_data *d, char **argv)
{
	d->stdin_copy = dup(STDIN_FILENO);
	d->file1 = open("here_doc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->file1 < 0)
		return ;
	while (1)
	{
		write(1, "heredoc> ", 9);
		d->line = get_next_line(stdin_copy);
		if (!d->line)
			msg_err("Line", d->here_doc);
		if (!ft_strncmp(argv[2], d->line, ft_strlen(argv[2])))
		{
			close(d->stdin_copy);
			get_next_line(d->stdin_copy);
			break ;
		}
		write(d->file1, d->line, ft_strlen(d->line));
		free(d->line);
	}
	close(d->file1);
	d->file1 = open("here_doc.tmp", O_RDONLY);
	d->file2 = open(argv[d->n_cmd + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->file1 < 0 || d->file2 < 0)
		msg_err("Heredoc", d->here_doc);
}
