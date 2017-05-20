/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:48:46 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 20:28:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_error(char *argv)
{
	int 		len;
	const char	*last_four;

	len = strlen(argv);
	last_four = &argv[len-4];
	if (len < 5 || ft_strncmp(".fdf", last_four, 5) != 0)
		ft_puterror("ERROR : input file is not compatible");
}


int		main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		ft_puterror("Usage : ./fdf <filename> [ ... ]");
	file_error(argv[1]);
	initenv(&env);
	ft_read(argv[1], &env);
	init_zoom(&env);
	parse(&env);
	fill_img(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook (env.win, mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
