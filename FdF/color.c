/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:04:18 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/18 01:33:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	put_color(t_env *env, int x0, int y0)
{
	if (COLOR == 0)
		DATA[x0 * WIDTH + y0] = LIGHTBLUE;
	if (COLOR == 1)
		DATA[x0 * WIDTH + y0] = RED;
	if (COLOR == 2)
		DATA[x0 * WIDTH + y0] = WHITE;
	if (COLOR == 3)
		DATA[x0 * WIDTH + y0] = GREEN;
	/*
	if (COLOR == 4)
		DATA[x0 * WIDTH + y0] = FRANCE;
	if (COLOR == 5)
		DATA[x0 * WIDTH + y0] = TERRE;
	*/
}
