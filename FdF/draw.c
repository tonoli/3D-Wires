/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/16 17:55:44 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define COLOR 0xFFFFFF

/*
void	init_diff(t_env *env, t_point start, t_point end)
{
	DIFF.x = end.x - start.x;
	DIFF.y = end.y - start.y;
	DIFF.absx = abs(DIFF.x);
	DIFF.absy = abs(DIFF.y);
}

void	draw(t_env *env, t_point start, t_point end)
{
	int x0 = start.x;
	int y0 = start.y;
	int x1 = end.x;
	int y1 = end.y;

	if (x0 == x1 && y0 == y1)
		DATA[x0 * WIDTH + y0] = start.color;
	else
	{
		int sx = (x1 - x0 < 0) ? -1 : 1;
		int sy = (y1 - y0 < 0) ? -1 : 1;
		int dx = abs(x1 - x0);
		int dy = -abs(y1 - y0);
		int err = dx + dy;
		int e2;

		if ((-dy) < dx)
		{
			while (x0 != x1)
			{
				if ((x0 * WIDTH + y0) <= WIDTH*HEIGHT)
					DATA[x0 * WIDTH + y0] = start.color;
				if (x0 == x1 && y0 == y1) break;
				e2 = 2 * err;
				if (e2 >= dy)
				{
					err += dy;
					x0 += sx;
				}
				if (e2 <= dx)
				{
					err += dx;
					y0 += sy;
				}
			}
		}
		else
		{
			while (y0 != y1)
			{
				if ((x0 * WIDTH + y0) <= WIDTH*HEIGHT)
					DATA[x0 * WIDTH + y0] = start.color;
				if (x0 == x1 && y0 == y1) break;
				e2 = 2 * err;
				if (e2 >= dy)
				{
					err += dy;
					x0 += sx;
				}
				if (e2 <= dx)
				{
					err += dx;
					y0 += sy;
				}
			}
		}
	}
}




*/
void draw_one(t_env *env, int x0, int y0, int x1, int y1)
{
	int sx = (x1 - x0 < 0) ? -1 : 1;
	int sy = (y1 - y0 < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (x0 != x1)
	{
		if ((x0 * WIDTH + y0) <= WIDTH * HEIGHT && x0 > 0 && y0 > 0)
			DATA[x0 * WIDTH + y0] = COLOR;
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= DIFX)
		{
			err += DIFY;
			x0 += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			y0 += sy;
		}
	}
}

void draw_two(t_env *env, int x0, int y0, int x1, int y1)
{
	int sx = (x1 - x0 < 0) ? -1 : 1;
	int sy = (y1 - y0 < 0) ? -1 : 1;
	int err = DIFX + DIFY;
	int e2;

	while (y0 != y1)
	{
		if ((x0 * WIDTH + y0) <= WIDTH * HEIGHT && x0 > 0 && y0 > 0)
			DATA[x0 * WIDTH + y0] = COLOR;
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= DIFY)
		{
			err += DIFY;
			x0 += sx;
		}
		if (e2 <= DIFX)
		{
			err += DIFX;
			y0 += sy;
		}
	}
}


void	draw(t_env *env, t_point start, t_point end)
{
	env->dx = abs(end.x - start.x);
	env->dy = -abs(end.y - start.y);

	if (start.x == end.x && start.y == end.y)
		DATA[start.x * WIDTH + start.y] = start.color;
	else
	{
		if ((-env->dy) < env->dx)
			draw_one(env, start.x, start.y, end.x, end.y);
		else
			draw_two(env, start.x, start.y, end.x, end.y);
	}
}
