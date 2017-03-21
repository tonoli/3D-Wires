/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/21 20:03:13 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		get_size(char *path, t_env *env)
{
	int fd;
	char *line;
	int nb_col;
	int j;
	int i;

	nb_col = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = ft_tablen(ft_strsplit(line, ' '));
		if (i > nb_col && nb_col == 0)
			nb_col = i;
		if (i != nb_col)
			return (0);
		j++;
	}
	env->lines = j;
	env->col = nb_col;
	close(fd);
	return (1);
}

int		ft_read(char *path, t_env *env)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;
	int		j;

	if (!(get_size(path, env)))
	{
		ft_putendl("Warning the file has an error.");
		return (0);
	}
	if (!(env->mapi = malloc(sizeof(int *) * env->lines)))
		return (0);
	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < env->lines)
	{
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		if (!(env->mapi[i] = malloc(sizeof(int) * env->col)))
			return (0);
		j = -1;
		while (++j < env->col)
			env->mapi[i][j] = ft_atoi(tab[j]);
	}
	close (fd);
	return (1);
}
