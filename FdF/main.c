/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:48:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/01/22 16:11:56 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int bpp;
	int sizeline;
	int endian;
	int   *img;
	char  *data;
	void  *mlx_ptr;
	void  *win_ptr;
	int   pixel_nbr;
	
	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	pixel_nbr = 0;
	mlx_ptr = mlx_init();
	img = mlx_new_image(mlx_ptr, 300, 300);
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	printf("%d, %d, %d\n", bpp, sizeline, endian);
	while (pixel_nbr < 360000)
	{
		data[pixel_nbr] = 50;
		pixel_nbr++;
	}
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Fenetre de Astaroth");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100, 100);
	mlx_loop(mlx_ptr);
}
