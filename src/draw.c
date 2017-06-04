/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 23:28:42 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_one(t_env *env, t_point start, t_point end)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (end.x - start.x < 0) ? -1 : 1;
	sy = (end.y - start.y < 0) ? -1 : 1;
	err = DIFX + DIFY;
	while (start.x != end.x)
	{
		if ((start.x * WIDTH + start.y) <= WIDTH * HEIGHT && start.x > 0
			&& start.y > 0 && start.y < WIDTH && start.x < HEIGHT)
			put_color(env, start, end);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		err += (e2 >= DIFY) ? DIFY : 0;
		start.x += (e2 >= DIFY) ? sx : 0;
		err += (e2 <= DIFX) ? DIFX : 0;
		start.y += (e2 <= DIFX) ? sy : 0;
	}
}

void	draw_two(t_env *env, t_point start, t_point end)
{
	int sx;
	int sy;
	int err;
	int e2;

	sx = (end.x - start.x < 0) ? -1 : 1;
	sy = (end.y - start.y < 0) ? -1 : 1;
	err = DIFX + DIFY;
	while (start.y != end.y)
	{
		if ((start.x * WIDTH + start.y) <= WIDTH * HEIGHT && start.x > 0
			&& start.y > 0 && start.y < WIDTH && start.x < HEIGHT)
			put_color(env, start, end);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		err += (e2 >= DIFY) ? DIFY : 0;
		start.x += (e2 >= DIFY) ? sx : 0;
		err += (e2 <= DIFX) ? DIFX : 0;
		start.y += (e2 <= DIFX) ? sy : 0;
	}
}

void	draw(t_env *env, t_point start, t_point end)
{
	env->dx = abs(end.x - start.x);
	env->dy = -abs(end.y - start.y);
	if ((-env->dy) < env->dx)
		draw_one(env, start, end);
	else
		draw_two(env, start, end);
}
