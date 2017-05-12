/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:08:05 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/11 21:26:31 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_diff(t_diff *diff, t_point start, t_point end)
{
	diff->x = end.x - start.x;
	diff->y = end.y - start.y;
	diff->abs_x = abs(diff->x);
	diff->abs_y = abs(diff->y);
}

void	draw_one(t_env *env, t_point start, t_point end)
{
	int		e;
	int		inc_x;
	int		inc_y;

	inc_x = (env->diff.x > 0) ? 1 : -1;
	inc_y = (env->diff.y > 0) ? 1 : -1;
	e = -env->diff.abs_x;
	while (start.x <= end.x)
	{
		fill_pixel(start.x, start.y, env);
		if ((e += 2 * env->diff.abs_y) >= 0)
		{
			start.y += inc_y ;
			e -= 2 * env->diff.abs_x;
		}
		start.x += inc_x;
	}
}

void	draw_two(t_env *env, t_point start, t_point end)
{
	int		e;
	int		inc_x;
	int		inc_y;

	inc_x = (env->diff.x > 0) ? 1 : -1;
	inc_y = (env->diff.y > 0) ? 1 : -1;
	e = -env->diff.abs_y;
	while (start.y <= end.y)
	{
		fill_pixel(start.y, start.x, env);
		if ((e += 2 * env->diff.abs_x) >= 0)
		{
			start.x += inc_x ;
			e -= 2 * env->diff.abs_y;
		}
		start.y += inc_y;
	}
}

void	draw(t_env *env, t_point start, t_point end)
{
	init_diff(&env->diff, start, end);
	if (env->diff.abs_x > env->diff.abs_y)
		draw_one(env, start, end);
	else
		draw_two(env, start, end);
}
