/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:21:53 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 23:15:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit(t_env *env)
{
	new_img(env);
	init_val(env);
	init_zoom(env);
	parse(env);
	fill_img(env);
}

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
		env->zoom += (key == PLUS) ? 0.1 : 0;
	if (env->zoom > 0.5 && env->zoom <= 1)
		env->zoom += (key == PLUS) ? 0.1 : -0.1;
	else if (env->zoom <= 5 && env->zoom > 1)
		env->zoom += (key == PLUS) ? 1 : -1;
	else if (env->zoom > 5 && env->zoom <= 100)
		env->zoom += (key == PLUS) ? 5 : -5;
	else if (env->zoom > 100)
		env->zoom += (key == PLUS) ? 0 : -5;
	parse(env);
	fill_img(env);
}

void	deepth(t_env *env, int key)
{
	new_img(env);
	if (key == PAGEUP)
		env->deepth += 2;
	else if (key == PAGEDOWN)
		env->deepth -= 2;
	parse(env);
	fill_img(env);
}

void	rotate(t_env *env, int key)
{
	new_img(env);
	if (PROJ == 1)
		ROTI0 += (key == A)? 0.1 : -0.1;
	else
		ROTP += (key == A)? 0.1 : -0.1;
	if (key == W)
	{
		ROTI1 += 0.1;
	}
	else if (key == S)
		ROTI1 -= 0.1;
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

void	color(t_env *env)
{
	new_img(env);
	if (COLOR == 4)
		COLOR = 0;
	else
		COLOR++;
	parse(env);
	fill_img(env);
}

int	mouse_hook(int bouton, int x, int y, t_env *env)
{
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 170 && y <= 202)
		color(env);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 100 && y <= 132)
		reinit(env);
	if (bouton == 1 && x >= 9 && x <= 41 && y >= 100 && y <= 132)
		proj(env);
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
	else if (key == W || key == S || key == A || key == D || key == Z || key == X || key == C || key == V)
		rotate(env, key);
	else if (key == SPACE)
		proj(env);
	else if (key == PAGEUP || key == PAGEDOWN)
		deepth(env, key);
	else if (key == R)
		reinit(env);
	return (0);
}
