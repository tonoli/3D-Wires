/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:45:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/14 00:17:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	draw_horizontal_lines(t_env *env)
{
	int 	x;
	int 	y;

	x = 0;
	while (x < env->lines - 1)
	{
		y = 0;
		while(y < env->col - 1)
		{
			//ft_putendl("YOU");
			draw(env, env->grid[x][y], env->grid[x][y + 1]);
			//ft_putendl("FUCK");
			y++;
		}
		draw(env, env->grid[x][env->col -1], env->grid[x + 1][env->col - 1]);
		x++;
	}
}

void	draw_vertical_lines(t_env *env)
{
	int 	x;
	int 	y;

	y = 0;
	while (y < env->col - 1)
	{
		x = 0;
		while(x < env->lines - 1)
		{
			//ft_putendl("I");
			draw(env, env->grid[x][y], env->grid[x + 1][y]);
			//ft_putendl("HATE");
			x++;
		}
		draw(env, env->grid[env->lines -1][y], env->grid[env->lines -1][y + 1]);
		y++;
	}
}

void		draw_lines(t_env *env)
{
	draw_horizontal_lines(env);
	draw_vertical_lines(env);
}
