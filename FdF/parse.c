/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:38:25 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/12 22:28:36 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define INIT_X	400
#define INIT_Y	200

void	parse(t_env *env)
{
	int		x;
	int		y;

	env->grid = (t_point **)malloc(sizeof(t_point *) * env->lines);
	y = 0;
	while (y < env->lines)
	{
		env->grid[y] = (t_point *)malloc(sizeof(t_point) * env->col);
		x = 0;
		while (x < env->col)
		{
			env->grid[y][x].x = (x - y) * env->view.x + INIT_X;
			env->grid[y][x].y = (x + y) * env->view.y + INIT_Y -
				(env->mapi[y][x] * env->depth);
			x++;
		}
		y++;
	}
}
