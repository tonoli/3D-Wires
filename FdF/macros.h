/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:46:04 by itonoli-          #+#    #+#             */
/*   Updated: 2017/05/17 00:28:01 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Elements of ENV Structure
 */


#define MLX env->mlx
#define WIN env->win
#define IMG env->ptr_img
#define DATA env->img_data
#define MAP env->mapi
#define GRID env->grid
#define POSS env->poss
#define BPP env->bpp
#define SL env->size_line
#define ENDIAN env->endian
#define LINES env->lines
#define COL env->col
#define DIFX env->dx
#define DIFY env->dy
#define ROT env->rot


/*int		zoom;
int		deepth;
int		move_h;
int		move_v;
int		lines;
int		col;
int		bpp;
int		size_line;
int		endian;
*/

/*
 * Keyboard numbers
 */

#define UP			126
#define DOWN		125
#define LEFT		123
#define RIGHT		124
#define PLUS		69
#define MOINS		78
#define SPACE		49
#define W			13
#define S			1
#define A			0
#define D			2
