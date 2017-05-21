/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:07:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 19:10:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	closehelp(t_env *env)
{
	HELPI = 1;
	new_img(env);
	parse(env);
	fill_img(env);
}

void	openhelp(t_env *env)
{
	int x;
	int y;

	HELPI = 0;
	x = 1000;
	while (++x < 1310)
	{
		y = 600;
		while (++y < 850)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, WHITE);
		}
	}
	mlx_string_put (env->mlx, env->win, 1295, 605, BLACK, "X");
	mlx_string_put (env->mlx, env->win, 1020, 620, GREEN, "HELP MENU");
	mlx_string_put (env->mlx, env->win, 1020, 650, RED, "Rotation : A & D");
	mlx_string_put (env->mlx, env->win, 1020, 680, RED, "Deepth : PageUp & PageDown");
	mlx_string_put (env->mlx, env->win, 1020, 710, RED, "Zoom : + & -");
	mlx_string_put (env->mlx, env->win, 1020, 740, RED, "Move : Arrows");
	mlx_string_put (env->mlx, env->win, 1020, 770, RED, "Reset : R");
	mlx_string_put (env->mlx, env->win, 1230, 820, BLACK, "(c)IT2M");
}
