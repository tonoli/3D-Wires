/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:45:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/12 19:18:56 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vertical_lines(t_env *env)
{
	int		x;
	int		y;
	int		height;
	int		width;

	height = env->lines;
	width = env->col;
	x = 0;
	while (x < height - 1)
	{
		y = 0;
		while (y < width - 1)
		{
			ft_putendl("DRAW VERT START");
			draw(env, env->grid[x][y], env->grid[x][y + 1]);
			y++;
		}
		draw(env, env->grid[x][width - 1], env->grid[x + 1][width - 1]);
		x++;
	}
	ft_putendl("DRAW VERT OVER");
}

static void	draw_horizontal_lines(t_env *env)
{
	int		x;
	int		y;
	int		height;
	int		width;

	height = env->lines;
	width = env->col;
	x = 0;
	while (x < width - 1)
	{
		y = 0;
		while (y < height - 1)
		{
			ft_putendl("DRAW HORI START");
			draw(env, env->grid[y][x], env->grid[y + 1][x]);
			y++;
		}
		draw(env, env->grid[height - 1][x], env->grid[height - 1][x + 1]);
		x++;
	}
	ft_putendl("DRAW HORI OVER");
}

void		draw_lines(t_env *env)
{
	draw_vertical_lines(env);
	draw_horizontal_lines(env);
}
/*
void init_start_end(t_env *env, int current_x, int current_y)
{


	 *  y = y + z/2 && z = mapi[x][y];

	int next_x;
	int next_y;

	next_x = current_x;
	next_y = current_y + 1;
	env->start.x = current_x;
	env->start.y = current_y + (env->mapi[current_x][current_y]/2);
	env->end.x = next_x;
	env->end.y = next_y + (env->mapi[next_x][next_y]/2);
}

void init_start_end_2(t_env *env, int current_x, int current_y)
{
	int next_x;
	int next_y;

	next_x = current_x + 1;
	next_y = current_y;
	env->start.x = current_x;
	env->start.y = current_y + (env->mapi[current_x][current_y]/2);
	env->end.x = next_x;
	env->end.y = next_y + (env->mapi[next_x][next_y]/2);
}

void	draw_horizontal_lines(t_env *env)
{
	int 	current_x;
	int 	current_y;
	int		height;
	int		width;

	height = env->lines;
	width = env->col;
	current_x = -1;
	while (++current_x < height - 1)
	{
		current_y = -1;
		while(++current_y < width - 1)
		{
			draw(env, env->start, env->end);
		}
	}
}

void	draw_col(t_env *env)
{
	int 	current_x;
	int 	current_y;

	current_y = -1;
	while (++current_y < env->col)
	{
		current_x = -1;
		while(++current_x < env->lines)
		{
			init_start_end_2(env, current_x, current_y);
			draw(env, env->start, env->end);
		}
	}
}
*/ 

