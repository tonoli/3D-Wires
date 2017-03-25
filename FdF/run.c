/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:08:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/03/25 02:15:11 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#define ESC			53

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	run(void* win, t_env *env)
{
	t_data	data;

	data.win = win;
	data.env = env;
	mlx_expose_hook(env -> win, draw, &env);
	mlx_key_hook(env -> win, key_hook, &env);
}
