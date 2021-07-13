/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:26:33 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 07:35:59 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	y_rotation(t_fdf **fdf, double *roty, int up)
{
	int			x;
	int			y;
	int			dx;
	int			dz;
	t_points	**points;

	*roty = up == 1 ? *roty + 0.1 : *roty;
	*roty = up == 2 ? *roty - 0.1 : *roty;
	*roty = up == 3 ? 0 : *roty;
	points = (*fdf)->points;
	y = 0;
	while (y < (*fdf)->dr_y)
	{
		x = 0;
		while (x < (*fdf)->dr_x)
		{
			dx = points[y][x].tx;
			dz = points[y][x].tz;
			points[y][x].tx = points[y][x].tx * cos(*roty) + dz * sin(*roty);
			points[y][x].tz = -dx * sin(*roty) + dz * cos(*roty);
			x++;
		}
		y++;
	}
}

void	x_rotation(t_fdf **fdf, double *rotx, int up)
{
	int			x;
	int			y;
	int			dy;
	int			dz;
	t_points	**points;

	*rotx = up == 1 ? *rotx + 0.1 : *rotx;
	*rotx = up == 2 ? *rotx - 0.1 : *rotx;
	*rotx = up == 3 ? 0 : *rotx;
	points = (*fdf)->points;
	y = 0;
	while (y < (*fdf)->dr_y)
	{
		x = 0;
		while (x < (*fdf)->dr_x)
		{
			dy = points[y][x].ty;
			dz = points[y][x].tz;
			points[y][x].ty = points[y][x].ty * cos(*rotx) + dz * sin(*rotx);
			points[y][x].tz = -dy * sin(*rotx) + dz * cos(*rotx);
			x++;
		}
		y++;
	}
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

void	para(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	z--;
	z++;
	*x = previous_x;
	*y = previous_y;
}

void	init_scale(t_fdf **fdf)
{
	if (((*fdf)->dr_x >= 1 || (*fdf)->dr_y >= 1) &&
			((*fdf)->dr_x <= 20 || (*fdf)->dr_y <= 20))
		(*fdf)->scalexy = 30;
	else if (((*fdf)->dr_x >= 30 || (*fdf)->dr_y >= 30) &&
			((*fdf)->dr_x <= 200 || (*fdf)->dr_y <= 200))
		(*fdf)->scalexy = 3;
	else
		(*fdf)->scalexy = 1;
	(*fdf)->scalez = 1;
}
