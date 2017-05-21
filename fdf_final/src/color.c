/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:04:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 15:31:53 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
		c = LIGHTBLUE;
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

int		red_color(t_point start, t_point end)
{
	int	c;

	if (start.z == end.z)
	{
		if (start.z == 0)
			c = BLACK;
		else
			c = 0xbf360c;
	}
	else
		c = 0xfb8c00;
	return (c);
}

int		earth_color(t_point start, t_point end)
{
	int	c;

	if (start.z == end.z)
	{
		if (start.z == 0)
			c = LIGHTBLUE;
		else
			c = BROWN;
	}
	else
	{
		c = GREEN;
	}
	return (c);
}

void	put_color(t_env *env, t_point start, t_point end)
{
	if (start.color == 0)
	{
		if (COLOR == 0)
			DATA[start.x * WIDTH + start.y] = standard(start, end);
		if (COLOR == 1)
			DATA[start.x * WIDTH + start.y] = arg_color(start.x);
		if (COLOR == 2)
			DATA[start.x * WIDTH + start.y] = red_color(start, end);
		if (COLOR == 3)
			DATA[start.x * WIDTH + start.y] = earth_color(start, end);
		if (COLOR == 4)
			DATA[start.x * WIDTH + start.y] = LIGHTBLUE;
	}
	else
		DATA[start.x * WIDTH + start.y] = start.color;
}
