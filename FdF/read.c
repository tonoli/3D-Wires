/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 20:30:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		get_size(char *path, t_env *env)
{
	int fd;
	char *line;
	int nb_col;
	int nb_lines;
	int i;

	nb_col = 0;
	nb_lines = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i = ft_tablen(ft_strsplit(line, ' '));
		if (i > nb_col && nb_col == 0)
			nb_col = i;
		if (i != nb_col)
			return (1);
		nb_lines++;
	}
	env->lines = nb_lines;
	env->col = nb_col;
	close(fd);
	return (0);
}


void	ft_read(char *path, t_env *env)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;
	int		j;

	if (get_size(path, env))
		ft_puterror("ERROR: input file has a line error or is corrupted");
	if (!(env->mapi = malloc(sizeof(int *) * env->lines)))
		ft_puterror("ERROR : malloc failed");
	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < env->lines)
	{
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		if (!(env->mapi[i] = malloc(sizeof(int) * env->col)))
			ft_puterror("ERROR : malloc failed");
		j = -1;
		while (++j < env->col)
			env->mapi[i][j] = ft_atoi(tab[j]);
	}
	close (fd);
}
