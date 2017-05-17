/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:48:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/16 23:44:32 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mlx_key_hook(env.win, key_hook, &env);
//	run(env->win, &env);
	mlx_loop(env.mlx);
	return (0);
}
