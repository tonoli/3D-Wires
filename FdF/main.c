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

int		main(int argc, char **argv)
{
	t_env		*env;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ ... ]");
		return (0);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env -> mlx, WIDTH, HEIGHT, "FDF");
	read(argv[1], &env);
	run(env -> win, &env);
	mlx_loop(env -> mlx);
	return (0);
}
