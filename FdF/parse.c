/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:38:25 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/14 00:26:09 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define INIT_X	400
#define INIT_Y	400

void	parse(t_env *env)
{
	int		x;
	int		y;

	env->grid = (t_point **)malloc(sizeof(t_point *) * env->lines);
	x = 0;
	while (x < env->lines)
	{
		env->grid[x] = (t_point *)malloc(sizeof(t_point) * env->col);
		y = 0;
		while (y < env->col)
		{
			env->grid[x][y].x = x * 20 + INIT_X;
			env->grid[x][y].y = y * 20 + INIT_Y - env->mapi[x][y] * 1;
			y++;
		}
		x++;
	}
}
