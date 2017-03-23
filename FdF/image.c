/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:59:42 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/23 19:32:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	int		bpp;
	int		size_line;
	int		endian;

	env->ptr_img = mlx_new_image(env -> mlx, WIDTH, HEIGHT);
	env->img_str = mlx_get_data_addr(env->ptr_img, &bpp, &size_line, &endian);

}

void	fill_pixel(char *img_str, int x, int y, t_env *env)
{
	img_str[4 * x + 4 * WIDTH * y] = env->blue;
	img_str[4 * x + 4 * WIDTH * y + 1] = env->green;
	img_str[4 * x + 4 * WIDTH * y + 2] = env->red;
}

void	fill_img(t_env *env)
{
	// Prendre l'image et allumer tous les points necessaire grace
	// aux fonctions draw qui diront lesquels alluner  et fill_pixel qui
	// viendra les allumer deriere

}
