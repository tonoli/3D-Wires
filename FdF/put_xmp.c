/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:16:19 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/18 01:14:09 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char *logo[] = {
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXX.... .XXX     X. ....",
"XXXXXXXXXX.  ...XXXX .. XX. ....",
"XXXXXXXXX.... .XXXXX...XXX..  . ",
"XXXXXXXX......XXXXXX. XXXX....  ",
"XXXXXXX.   ..XXXXXXX.XXXXX. ....",
"XXXXXX..  ..XXXXXXXXXXXXXX..  . ",
"XXXXX .....XXXXXXXXXXXXXX... ..X",
"XXXX ..  .XXXXXXXXXXXXXX...  .XX",
"XXX. . ..XXXXXXXXXXXXXX.  .. XXX",
"XX . ...XXXXXXXXXXXXXX.     XXXX",
"X. ....XXXXXXXXXXXXXX.. .. XXXXX",
".......XXXXXXXXXXXXX..  ..XXXXXX",
"  .  .... ..... ..XX...  .XXXXX.",
" ...........  . ..XX..... XXXX..",
"............     .XX.. ...XXX...",
"........ . ..   ..XX.  ...XX..  ",
"XXXXXXXXXXXX.. ...XX...  .X...  ",
"XXXXXXXXXXXX .....XXXXXXXXXXXXXX",
"XXXXXXXXXXXX......XXXXXXXXXXXXXX",
"XXXXXXXXXXXX.. ...XXXXXXXXXXXXXX",
"XXXXXXXXXXXX... ..XXXXXXXXXXXXXX",
"XXXXXXXXXXXX......XXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

void put_xmp(t_env *env)
{
	int y = 0;
	int x;

	while (y < 32)
		{
			x = 0;
			while (x < 32)
			{
				if (logo[x][y] == '.' || logo[x][y] == ' ')
					mlx_pixel_put(env->mlx, env->win, y + 6, x, 0x000000);
				x++;
			}
		y++;
		}
}
