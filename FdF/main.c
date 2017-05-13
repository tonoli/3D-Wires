/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:48:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/12 22:30:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initenv(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Au Fil du Fer...");
	env->view.x = 10;
	env->view.y = 20;
	env->depth = 5;
	create_image(env);
}

int		main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ ... ]");
		return (0);
	}
	initenv(&env);
	ft_read(argv[1], &env);
	parse(&env);
	fill_img(&env);
//	run(env->win, &env);
	mlx_loop(env.mlx);
	return (0);
}
