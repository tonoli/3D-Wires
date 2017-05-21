/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:38:25 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 21:04:10 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parse_iso(t_env *env)
{
	int		x;
	int		y;

	if (!(env->grid = (t_point **)malloc(sizeof(t_point *) * LINES)))
		ft_puterror("ERROR : malloc failed");
	x = -1;
	while (++x < LINES)
	{
		if (!(env->grid[x] = (t_point *)malloc(sizeof(t_point) * COL)))
			ft_puterror("ERROR : malloc failed");
		y = -1;
		while (++y < COL)
		{

			GRID[x][y].x = (x * cos(0.6 + ROTI0) - y * sin(0.1 + ROTI0)) * env->zoom +
				env->move_v + MAP[x][y] * sin(-0.3) * env->deepth;
			GRID[x][y].y = (y * cos(ROTI0 + 0.1)  + sin(-0.3 + ROTI0) * x) * env->zoom +
				env->move_h + MAP[x][y] * cos(1.9) * env->deepth;
			GRID[x][y].z = MAP[x][y];
		}
	}
}


void	parse_parallel(t_env *env)
{
	int		x;
	int		y;

	if (!(env->grid = (t_point **)malloc(sizeof(t_point *) * LINES)))
		ft_puterror("ERROR : malloc failed");
	x = -1;
	while (++x < LINES)
	{
		if (!(env->grid[x] = (t_point *)malloc(sizeof(t_point) * COL)))
			ft_puterror("ERROR : malloc failed");
		y = -1;
		while (++y < COL)
		{
			GRID[x][y].x = (cos(ROTP) * x - sin(ROTP) * y) * env->zoom +
				env->move_v - MAP[x][y] * env->deepth;
			GRID[x][y].y = (cos(ROTP) * y + sin(ROTP) * x) * env->zoom +
				env->move_h - MAP[x][y] * env->deepth;
			GRID[x][y].z = MAP[x][y];
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
