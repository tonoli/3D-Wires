/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/28 20:06:39 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#define RD		0x27ABEC

static void	init_delta(t_delta *delta, t_point start, t_point end)
{
	delta->x = end.x - start.x;
	delta->y = end.y - start.y;
	delta->abs_x = abs(delta->x);
	delta->abs_y = abs(delta->y);
}

static void	draw_horz_line(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x / (double)delta.abs_x;
	dy = (double)delta.y / (double)delta.abs_x;
	i = 0;
	while (i <= delta.abs_x)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, (int)posx, (int)(posy + 0.5), RD);
		posx += dx;
		posy += dy;
		i++;
	}
}

static void	draw_vert_line(t_delta delta, t_mlx *mlx, double posx, double posy)
{
	double	dx;
	double	dy;
	int		i;

	dx = (double)delta.x / (double)delta.abs_y;
	dy = (double)delta.y / (double)delta.abs_y;
	i = 0;
	while (i <= delta.abs_y)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, (int)(posx + 0.5), (int)posy, RD);
		posx += dx;
		posy += dy;
		i++;
	}
}

void		draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_delta	delta;
	double	posx;
	double	posy;

	init_delta(&delta, start, end);
	posx = start.x;
	posy = start.y;
	if (delta.abs_y > delta.abs_x)
	{
		draw_vert_line(delta, mlx, posx, posy);
	}
	else
	{
		draw_horz_line(delta, mlx, posx, posy);
	}
}
