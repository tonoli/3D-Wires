/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 20:21:53 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/18 01:34:40 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reinit(t_env *env)
{
	new_img(env);
	init_val(env);
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
	if (key == PLUS)
		env->zoom += 5;
	else if (key == MOINS)
		env->zoom -=5;
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
	{
		if (key == A)
			ROTI0 += 0.1;
		else if (key == D)
			ROTI0 -= 0.1;
		printf("%s%f%s","RATI0 : ", ROTI0, "\n");
	}
	else
	{
		if (key == A)
			ROTP += 0.1;
		else if (key == D)
			ROTP -= 0.1;
	}
	if (key == W)
	{
		ROTI1 += 0.1;
	}
	else if (key == S)
		ROTI1 -= 0.1;
	printf("%s%f%s","RATI1 : ", ROTI1, "\n");
	ft_putendl(" ");
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
	if (COLOR == 3)
		COLOR = 0;
	else
		COLOR++;
	parse(env);
	fill_img(env);
}

int	mouse_hook(int bouton, int x, int y, t_env *env)
{
	if(x && y)
	if (bouton == 1)
		color(env);
	ft_putnbr(bouton);
	ft_putendl(" ");
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
