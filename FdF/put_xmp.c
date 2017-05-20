/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:16:19 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 23:31:07 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_xmp(t_env *env)
{
	int width;
	int height;

	LOGO = mlx_xpm_file_to_image(env->mlx, "xpm/favicon.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, LOGO, 9, 5);
	RESET = mlx_xpm_file_to_image(env->mlx, "xpm/reset.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, RESET, 9, 100);
	ICOLOR = mlx_xpm_file_to_image(env->mlx, "xpm/color.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, ICOLOR, 9, 170);
	HELP = mlx_xpm_file_to_image(env->mlx, "xpm/help.xpm", &width, &height);
	mlx_put_image_to_window(env->mlx, env->win, HELP, 9, 850);
}
