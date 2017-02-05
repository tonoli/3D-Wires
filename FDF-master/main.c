/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:57:29 by aliandie          #+#    #+#             */
/*   Updated: 2015/02/03 18:11:03 by aliandie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	char		*line;
	t_env		env;

	(void)ac;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1020, 1020, "nya");
	line = NULL;
	env.map = readmap(av[1], line);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
