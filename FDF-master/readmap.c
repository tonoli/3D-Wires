/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:57:01 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/03 18:37:33 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_tab(t_map *map, int i, char **tab)
{
	while (map->c >= 0)
	{
		map->map[map->l][map->c] = ft_atoi(tab[i]);
		map->c--;
		i++;
	}
}

t_map	readmap(char *f, char *line)
{
	char	**tab;
	int		fd;
	int		i;
	t_map	map;

	fd = open(f, O_RDONLY);
	map.map_line = gnl_counter(f, line);
	map.l = map.map_line - 1;
	map.map = (int**)malloc(sizeof(int*) * map.map_line);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[i])
			i++;
		map.map_col = i;
		map.c = map.map_col - 1;
		map.map[map.l] = (int*)malloc(sizeof(int) * i);
		i = 0;
		set_tab(&map, i, tab);
		map.l--;
	}
	close(fd);
	return (map);
}
