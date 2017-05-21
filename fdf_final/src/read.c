/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 23:38:28 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		env->tab = ft_strsplit(line, ' ');
		i = ft_tablen(env->tab);
		if (i > LINES && COL == 0)
			COL = i;
		if (i != COL)
			return (1);
		LINES++;
	}
	free(env->tab);
	close(fd);
	return (0);
}

long	get_zmax(t_env *env)
{
	int i;
	int j;

	env->z_max = 0;
	env->z_min = 0;
	i = -1;
	while (++i < LINES)
	{
		j = -1;
		while (++j < COL)
		{
			if (MAP[i][j] > env->z_max)
				env->z_max = MAP[i][j];
			if (MAP[i][j] < env->z_min)
				env->z_min = MAP[i][j];
		}
	}
	return (abs(env->z_min - env->z_max));
}

void	ft_read(char *path, t_env *env)
{
	int		fd;
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
		get_next_line(fd, &env->line);
		env->tab = ft_strsplit(env->line, ' ');
		if (!(env->mapi[i] = malloc(sizeof(int) * env->col)))
			ft_puterror("ERROR : malloc failed");
		j = -1;
		while (++j < env->col)
			env->mapi[i][j] = ft_atoi(env->tab[j]);
	}
	free(env->tab);
	close(fd);
}
