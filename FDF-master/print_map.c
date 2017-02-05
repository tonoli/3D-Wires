/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:41:37 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/04 13:39:01 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_setend(t_map m, t_point s, int j, t_env *env)
{
	t_point	e;

	if (s.i < m.map_line - 1)
	{
		e.x = ((sqrt(2)) / 2) * (((s.i + 1) * m.z) - (j * m.z)) + m.ct;
		e.y = (m.map[s.i + 1][j] *
(-5) - (1 / sqrt(6) * ((j * m.z) + ((s.i + 1) * m.z))));
		e.y = e.y + m.ct;
		draw_line(env, s, e, 0xFFFFFF);
	}
	if (j < m.map_col - 1)
	{
		e.x = ((sqrt(2)) / 2) * ((s.i * m.z) - ((j + 1) * m.z)) + m.ct;
		e.y = (m.map[s.i][j + 1] *
(-5) - (1 / sqrt(6) * (((j + 1) * m.z) + (s.i * m.z))));
		e.y = e.y + m.ct;
		draw_line(env, s, e, 0xFFFFFF);
	}
}

void	print_map(t_map map, t_env *env)
{
	int			j;
	t_point		s;

	s.i = 0;
	map.z = 50;
	map.ct = 600;
	while (s.i < map.map_line)
	{
		j = 0;
		while (j < map.map_col)
		{
			s.x = ((sqrt(2)) / 2) * ((s.i * map.z) - (j * map.z)) + map.ct;
			s.y = (map.map[s.i][j] *
(-5) - (1 / sqrt(6) * ((j * map.z) + (s.i * map.z))));
			s.y = s.y + map.ct;
			map_setend(map, s, j, env);
			j++;
		}
		s.i++;
	}
}
