
#include "fdf.h"

#define INIT_X	700
#define INIT_Y	200

void	parse(t_fdf *fdf)
{
	int		x;
	int		y;

	fdf->grid = (t_point **)malloc(sizeof(t_point *) * fdf->height);
	y = 0;
	while (y < fdf->height)
	{
		fdf->grid[y] = (t_point *)malloc(sizeof(t_point) * fdf->width);
		x = 0;
		while (x < fdf->width)
		{
			fdf->grid[y][x].x = (x - y) * fdf->view.x + INIT_X + fdf->pos.x;
			fdf->grid[y][x].y = (x + y) * fdf->view.y + INIT_Y -
								(fdf->input[y][x] * fdf->depth) + fdf->pos.y;
			x++;
		}
		y++;
	}
}
