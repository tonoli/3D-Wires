/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:45:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/11 21:29:48 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_start_end(t_env *env, int current_x, int current_y)
{

/*
 *  y = y + z/2 && z = mapi[x][y];
 */

	int next_x;
	int next_y;

	next_x = current_x;
	next_y = current_y + 1;
	env->start.x = current_x;
	env->start.y = current_y + (env->mapi[current_x][current_y]/2);
	env->end.x = next_x;
	env->end.y = next_y + (env->mapi[next_x][next_y]/2);
}

void init_start_end_2(t_env *env, int current_x, int current_y)
{
	int next_x;
	int next_y;

	next_x = current_x + 1;
	next_y = current_y;
	env->start.x = current_x;
	env->start.y = current_y + (env->mapi[current_x][current_y]/2);
	env->end.x = next_x;
	env->end.y = next_y + (env->mapi[next_x][next_y]/2);
}

void	draw_lines(t_env *env)
{
	int 	current_x;
	int 	current_y;

	current_x = -1;
	while (++current_x < env->lines)
	{
		current_y = -1;
		while(++current_y < env->col)
		{
			init_start_end(env, current_x, current_y);
			draw(env, env->start, env->end);
		}
	}
}

void	draw_col(t_env *env)
{
	int 	current_x;
	int 	current_y;

	current_y = -1;
	while (++current_y < env->col)
	{
		current_x = -1;
		while(++current_x < env->lines)
		{
			init_start_end_2(env, current_x, current_y);
			draw(env, env->start, env->end);
		}
	}
}
