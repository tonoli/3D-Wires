/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/22 12:02:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

int		read_number(char *str, t_env *env, int x, int y)
{
	int i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[++i]))
		;
	if (ft_strncmp(&str[i], ",0x", 3) == 0)
	{
		env->map_color[x][y] = strtol(&str[++i], NULL, 16);
		return (ft_atoi(str));
	}
	else if (str[i] == '\0')
	{
		env->map_color[x][y] = 0;
		return (ft_atoi(str));
	}
	else
	{
		ft_puterror("ERROR: input file has a line error or is corrupted");
		return (0);
	}
	return (0);
}

void	ft_read(char *path, t_env *env)
{
	int		fd;
	int		i;
	int		j;

	if (get_size(path, env))
		ft_puterror("ERROR: input file has a line error or is corrupted");
	env->mapi = ft_memtab(env->lines, env->col);
	env->map_color = ft_memtab(env->lines, env->col);
	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < env->lines)
	{
		get_next_line(fd, &env->line);
		env->tab = ft_strsplit(env->line, ' ');
		j = -1;
		while (++j < env->col)
			env->mapi[i][j] = read_number(env->tab[j], env, i, j);
	}
	free(env->tab);
	close(fd);
}
