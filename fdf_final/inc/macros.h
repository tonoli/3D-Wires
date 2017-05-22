/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:46:04 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/21 18:00:56 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "fdf.h"

# define MLX env->mlx
# define WIN env->win
# define IMG env->ptr_img
# define DATA env->img_data
# define MAP env->mapi
# define GRID env->grid
# define POSS env->poss
# define BPP env->bpp
# define SL env->size_line
# define ENDIAN env->endian
# define LINES env->lines
# define COL env->col
# define DIFX env->dx
# define DIFY env->dy
# define ROTP env->rotp
# define ROTI0 env->roti0
# define ROTI1 env->roti1
# define COLOR env->color
# define PROJ env->proj
# define LOGO env->logo
# define HELP env->icon_help
# define HELPI env->help
# define RESET env->icon_reset
# define ICOLOR env->icon_color
# define ISO env->iso
# define ZOOM env->icon_zoom

# define WIDTH		1360
# define HEIGHT		900

# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define PLUS		69
# define MOINS		78
# define PAGEUP		116
# define PAGEDOWN	121
# define SPACE		49
# define ESC_KEY	53
# define W			13
# define S			1
# define A			0
# define D			2
# define Z			6
# define X			7
# define C			8
# define V			9
# define R			15

# define LIGHTBLUE	0x4FC3F7
# define WHITE		0xFFFFFF
# define RED		0xF44336
# define GREEN		0x4CAF50
# define ORANGE		0xFB8C00
# define GREY		0x757575
# define BROWN		0x795548
# define BLACK		0x000000

#endif
