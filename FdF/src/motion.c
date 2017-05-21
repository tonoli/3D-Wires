/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:21:53 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 21:59:27 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
	if (env->zoom <= 0.5)
		env->zoom += (key == PLUS || key == 1) ? 0.1 : 0;
	if (env->zoom > 0.5 && env->zoom <= 1)
		env->zoom += (key == PLUS || key == 1) ? 0.1 : -0.1;
	else if (env->zoom <= 5 && env->zoom > 1)
		env->zoom += (key == PLUS || key == 1) ? 1 : -1;
	else if (env->zoom > 5 && env->zoom <= 100)
		env->zoom += (key == PLUS || key == 1) ? 5 : -5;
	else if (env->zoom > 100)
		env->zoom += (key == PLUS || key == 1) ? 0 : -5;
	parse(env);
	fill_img(env);
}

void	deepth(t_env *env, int key)
{
	new_img(env);
	if ((env->deepth > -20 && env->deepth < -1)
	|| (env->deepth > 1 && env->deepth < 20))
		env->deepth += (key == PAGEUP) ? 1 : -1;
	else if (env->deepth <= 1 && env->deepth >= -1)
		env->deepth += (key == PAGEUP) ? 0.2 : -0.2;
	else if (env->deepth <= -20)
		env->deepth += (key == PAGEUP) ? 1 : 0;
	else if (env->deepth >= 20)
		env->deepth += (key == PAGEUP) ? 0 : -1;
	parse(env);
	fill_img(env);
}


int	mouse_hook(int bouton, int x, int y, t_env *env)
{
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 110 && y <= 142)
		reinit(env);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 160 && y <= 192)
		color(env);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 210 && y <= 242)
		proj(env);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 260 && y <= 292)
		zoom(env, 1);
	if (bouton == 2 && x >= 9 && x <= 41 && y >= 260 && y <= 292)
		zoom(env, 2);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 850 && y <= 882)
		openhelp(env);
	if (bouton == 1 && x >= 1295 && x <= 1305 && y >= 605 && y <= 625)
		closehelp(env);
	return (0);
}

int	key_hook(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(env, key);
	else if (key == PLUS || key == MOINS)
		zoom(env, key);
	else if (key == A || key == D)
		rotate(env, key);
	else if (key == SPACE)
		proj(env);
	else if (key == PAGEUP || key == PAGEDOWN)
		deepth(env, key);
	else if (key == R)
		reinit(env);
	return (0);
}
