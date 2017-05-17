/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:45:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/16 11:41:23 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	draw_horizontal_lines(t_env *env)
{
	int 	x;
	int 	y;

	x = -1;
	while (++x < LINES - 1)
	{
		y = -1;
		while(++y < COL - 1)
			draw(env, GRID[x][y], GRID[x][y + 1]);
		draw(env, GRID[x][y], GRID[x + 1][y]);
	}
}

void	draw_vertical_lines(t_env *env)
{
	int 	x;
	int 	y;

	y = -1;
	while (++y < COL - 1)
	{
		x = -1;
		while(++x < LINES - 1)
			draw(env, GRID[x][y], GRID[x + 1][y]);
		draw(env, GRID[x][y], GRID[x][y + 1]);
	}
}

void		draw_lines(t_env *env)
{
	draw_horizontal_lines(env);
	draw_vertical_lines(env);
}
