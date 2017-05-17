/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:38:25 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/17 00:32:52 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_iso(t_env *env)
{
	int		x;
	int		y;

	env->grid = (t_point **)malloc(sizeof(t_point *) * LINES);
	x = -1;
	while (++x < LINES)
	{
		env->grid[x] = (t_point *)malloc(sizeof(t_point) * COL);
		y = -1;
		while (++y < COL)
		{
			GRID[x][y].x = (cos(-0.6) * x - sin(-0.2) * y) * env->zoom +
				env->move_v - MAP[x][y] * env->deepth;
			GRID[x][y].y = (cos(-0.2) * y + sin(-0.6) * x) * env->zoom +
				env->move_h - MAP[x][y] * env->deepth;
		}
	}
}


void	parse_parallel(t_env *env)
{
	int		x;
	int		y;

	env->grid = (t_point **)malloc(sizeof(t_point *) * LINES);
	x = -1;
	while (++x < LINES)
	{
		env->grid[x] = (t_point *)malloc(sizeof(t_point) * COL);
		y = -1;
		while (++y < COL)
		{
			GRID[x][y].x = (cos(ROT) * x - sin(ROT) * y) * env->zoom +
				env->move_v - MAP[x][y] * env->deepth;
			GRID[x][y].y = (cos(ROT) * y + sin(ROT) * x) * env->zoom +
				env->move_h - MAP[x][y] * env->deepth;
		}
	}
}

void	parse(t_env *env)
{
	if (env->proj == 0)
		parse_parallel(env);
	if (env->proj == 1)
		parse_iso(env);
}
