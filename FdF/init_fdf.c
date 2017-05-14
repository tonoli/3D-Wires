/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:58:30 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/13 21:18:56 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initenv(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Au Fil du Fer...");
	env->ptr_img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_data = (int *)mlx_get_data_addr(env->ptr_img, &env->bpp, &env->size_line, &env->endian);
}
