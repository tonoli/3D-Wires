/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/28 20:06:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_lines(char *path)
{
	int fd;
	char *line;
	int nb_lines;

	nb_lines = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		nb_lines++;
	close(fd);
	return (nb_lines);
}

int	get_col(char *path)
{
	int fd;
	char *line;
	int nb_col;

	nb_lines = 0;
	fd = open(path, O_RDONLY);
	get_next_line(fd, &line);
	nb_col = ft_strlen(ft_strsplit(line, ' '));
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		i = ft_strlen(tab);
		if (i > nb_col)
			reutrn(-1);
	}
	return (nb_col);
}

int	ft_read(char *path, t_env *env)
{
	int		fd;
	char	*line;
	char	i;
	char	j;

	env.lines = get_lines(path);
	env.col	= get_col(path);
	if (env.col == -1)
	{
		ft_putendl("Warning the file has an error.");
		return(0);
	}
	env.map = (int **)malloc(sizeof(int) * env->lines);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < env->lines)
	{
		get_next_line(fd, &line);
		env.map[i] = (int *)malloc(sizeof(int) * env->col);
		j = 0;
		while (j < env->col)
		{
			env.map[i][j] = (int)		}
	}
	close (fd);
}
