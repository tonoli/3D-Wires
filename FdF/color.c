/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:04:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/19 22:08:57 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		standard(t_point start, t_point end)
{
	int	c;

	if (start.z == end.z)
	{
		if (start.z == 0)
			c = GREY;
		else
			c = WHITE;
	}
	else
		c = ORANGE;
	return (c);
}

int		arg_color(int x)
{
	int	c;

	c = LIGHTBLUE;
	if (x >= HEIGHT / 3)
		c = WHITE;
	if (x >= (HEIGHT / 3) * 2)
		c = LIGHTBLUE;
	return (c);
}

int		mars_color(t_point start, t_point end)
{
	int	c;

	if (start.z == end.z)
	{
		if (start.z == 0)
			c = 0x000000;
		else
			c = 0xbf360c;
	}
	else
		c = 0xfb8c00;
	return (c);
}

int		earth_color(t_point start, t_point end)
{
	int	color;

	if (start.z == end.z)
	{
		if (start.z == 0)
			color = LIGHTBLUE;
		else
			color = BROWN;
	}
	else
	{
		color = GREEN;
	}
	return (color);
}

void	put_color(t_env *env, t_point start, t_point end)
{
	if (COLOR == 0 && env->proj == 1)
		DATA[start.x * WIDTH + start.y] = standard(start, end);
	if (COLOR == 1 && env->proj == 1)
		DATA[start.x * WIDTH + start.y] = arg_color(start.x);
	if (COLOR == 2 && env->proj == 1)
		DATA[start.x * WIDTH + start.y] = mars_color(start, end);
	if (COLOR == 3 && env->proj == 1)
		DATA[start.x * WIDTH + start.y] = earth_color(start, end);
	if (COLOR == 4 && env->proj == 1)
		DATA[start.x * WIDTH + start.y] = LIGHTBLUE;
	if (COLOR == 0 && env->proj == 0)
		DATA[start.x * WIDTH + start.y] = GREY;
	if (COLOR == 1 && env->proj == 0)
		DATA[start.x * WIDTH + start.y] = arg_color(start.x);
	if (COLOR == 2 && env->proj == 0)
		DATA[start.x * WIDTH + start.y] = 0xfb8c00;
	if (COLOR == 3 && env->proj == 0)
		DATA[start.x * WIDTH + start.y] = BROWN;
	if (COLOR == 4 && env->proj == 0)
		DATA[start.x * WIDTH + start.y] = LIGHTBLUE;
}
