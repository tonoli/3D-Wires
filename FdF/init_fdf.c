/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:58:30 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/18 02:00:23 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_val(t_env *env)
{
	env->move_v = 180;
	env->move_h = 450;
	env->deepth = 7;
	env->poss.x = 0;
	env->poss.y = 0;
	env->zoom = 40 * 1/20 * COL ;
	env->rotp = 0;
	env->roti0 = -0.4;
	env->roti1 = 0;
	env->color = 0;
	env->proj = 1;
}

void	initenv(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Au Fil du Fer...");
	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = (int *)mlx_get_data_addr(env->ptr_img, &env->bpp,
		&env->size_line, &env->endian);
	init_val(env);
	new_menu(env);
}
