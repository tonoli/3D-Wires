/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:21:53 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/17 00:28:57 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_env *env, int key)
{
	new_img(env);
	if (key == UP)
		env->move_v -= 10;
	else if (key == DOWN)
		env->move_v += 10;
	else if (key == LEFT)
		env->move_h -=10;
	else if (key == RIGHT)
		env->move_h += 10;
	parse(env);
	fill_img(env);
}

void	zoom(t_env *env, int key)
{
	new_img(env);
	if (key == PLUS)
		env->zoom += 5;
	else if (key == MOINS)
		env->zoom -=5;
	parse(env);
	fill_img(env);
}

void	rotate(t_env *env, int key)
{
	new_img(env);
	if (key == W)
	{
		env->deepth += 2;
	}
	else if (key == S)
		env->deepth -= 2;
	if (key == A)
		env->rot += 0.2;
	else if (key == D)
		env->rot -= 0.2;
	parse(env);
	fill_img(env);
}
void	proj(t_env *env)
{
	new_img(env);
	env->proj = (env->proj == 0) ? 1 : 0;
	parse(env);
	fill_img(env);
}

int	key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(env, key);
	else if (key == PLUS || key == MOINS)
		zoom(env, key);
	else if (key == W || key == S || key == A || key == D)
		rotate(env, key);
	else if (key == SPACE)
		proj(env);
	return (0);
}
