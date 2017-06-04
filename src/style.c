/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 19:10:57 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/20 23:39:13 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	reinit(t_env *env)
{
	new_img(env);
	init_val(env);
	init_zoom_deepth(env);
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

void	rotate(t_env *env, int key)
{
	new_img(env);
	if (PROJ == 1)
		ROTI0 += (key == A) ? 0.1 : -0.1;
	else
		ROTP += (key == A) ? 0.1 : -0.1;
	parse(env);
	fill_img(env);
}
