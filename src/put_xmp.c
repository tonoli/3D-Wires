/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:16:19 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 17:11:02 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_xmp(t_env *env)
{
	int width;
	int height;

	LOGO = mlx_xpm_file_to_image(env->mlx, "xpm/favicon.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, LOGO, 9, 5);
	RESET = mlx_xpm_file_to_image(env->mlx, "xpm/reset.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, RESET, 9, 110);
	ICOLOR = mlx_xpm_file_to_image(env->mlx, "xpm/color.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ICOLOR, 9, 160);
	ISO = mlx_xpm_file_to_image(env->mlx, "xpm/iso.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ISO, 9, 210);
	ZOOM = mlx_xpm_file_to_image(env->mlx, "xpm/zoom.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ZOOM, 9, 260);
	HELP = mlx_xpm_file_to_image(env->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, HELP, 9, 850);
}
