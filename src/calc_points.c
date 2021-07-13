/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 20:55:46 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 06:45:47 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_scale(t_fdf **fdf)
{
	int			x;
	int			y;
	t_points	**points;

	y = 0;
	points = (*fdf)->points;
	while (y < (*fdf)->dr_y)
	{
		x = 0;
		while (x < (*fdf)->dr_x)
		{
			points[y][x].tx = points[y][x].x * (*fdf)->scalexy;
			points[y][x].ty = ((points[y][x].y * (*fdf)->scalexy));
			points[y][x].tz = points[y][x].z * (*fdf)->scalez;
			x++;
		}
		y++;
	}
}

void	iso_app(t_fdf **fdf)
{
	int			x;
	int			y;
	t_points	**points;
	int			drx;
	int			dry;

	drx = (*fdf)->dr_x - 1;
	dry = (*fdf)->dr_y - 1;
	y = 0;
	x = 0;
	points = (*fdf)->points;
	while (y < (*fdf)->dr_y)
	{
		while (x < (*fdf)->dr_x)
		{
			iso(&points[y][x].tx, &points[y][x].ty, points[y][x].tz);
			x++;
		}
		x = 0;
		y++;
	}
}

void	para_app(t_fdf **fdf)
{
	int			x;
	int			y;
	t_points	**points;
	int			drx;
	int			dry;

	drx = (*fdf)->dr_x - 1;
	dry = (*fdf)->dr_y - 1;
	y = 0;
	x = 0;
	points = (*fdf)->points;
	while (y < (*fdf)->dr_y)
	{
		while (x < (*fdf)->dr_x)
		{
			para(&points[y][x].tx, &points[y][x].ty, points[y][x].tz);
			x++;
		}
		x = 0;
		y++;
	}
}

void	center_app(t_fdf **fdf)
{
	int			x;
	int			y;
	t_points	**points;

	y = 0;
	x = 0;
	points = (*fdf)->points;
	while (y < (*fdf)->dr_y)
	{
		while (x < (*fdf)->dr_x)
		{
			points[y][x].tx = points[y][x].tx + (*fdf)->sx;
			points[y][x].ty = points[y][x].ty + (*fdf)->sy;
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw(t_fdf *fdf)
{
	int			x;
	int			y;
	t_points	**points;

	y = 0;
	x = 0;
	points = fdf->points;
	while (y < fdf->dr_y)
	{
		while (x < fdf->dr_x)
		{
			if (x + 1 < fdf->dr_x)
			{
				line(fdf, points[y][x], points[y][x + 1]);
			}
			if (y + 1 < fdf->dr_y)
			{
				line(fdf, points[y][x], points[y + 1][x]);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
