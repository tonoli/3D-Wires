/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:32:05 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/03 18:07:46 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_env *e, t_point start, t_point end, int color)
{
	t_line	line;
	int		err[2];

	line.start.x = abs(end.x - start.x);
	line.end.x = start.x < end.x ? 1 : -1;
	line.start.y = abs(end.y - start.y);
	line.end.y = start.y < end.y ? 1 : -1;
	err[0] = (line.start.x > line.start.y ? line.start.x : -line.start.y) / 2;
	while (1)
	{
		mlx_pixel_put(e->mlx, e->win, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			return ;
		err[1] = err[0];
		if (err[1] > -line.start.x)
		{
			err[0] -= line.start.y;
			start.x += line.end.x;
		}
		if (err[1] < line.start.y)
		{
			err[0] += line.start.x;
			start.y += line.end.y;
		}
	}
}
