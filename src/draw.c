/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 03:51:17 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/23 04:06:13 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_x(t_fdf *fdf, t_points src, t_points dst)
{
	int dx;
	int dy;
	int acm;
	int s[2];

	acm = 0;
	dx = abs(dst.tx - src.tx);
	dy = abs(dst.ty - src.ty);
	s[0] = (src.tx < dst.tx ? 1 : -1);
	s[1] = (src.ty < dst.ty ? 1 : -1);
	if (dx > dy)
	{
		while (src.tx != dst.tx || src.ty != dst.ty)
		{
			put_pixel(fdf, src, dst);
			src.tx += s[0];
			acm = acm + dy;
			if (acm >= dx)
			{
				src.ty += s[1];
				acm = acm - dx;
			}
		}
	}
}

void	line_y(t_fdf *fdf, t_points src, t_points dst)
{
	int dx;
	int dy;
	int acm;
	int s[2];

	acm = 0;
	dx = abs(dst.tx - src.tx);
	dy = abs(dst.ty - src.ty);
	s[0] = (src.tx < dst.tx ? 1 : -1);
	s[1] = (src.ty < dst.ty ? 1 : -1);
	if (dy >= dx)
	{
		while (src.tx != dst.tx || src.ty != dst.ty)
		{
			put_pixel(fdf, src, dst);
			src.ty += s[1];
			acm = acm + dx;
			if (acm >= dy)
			{
				src.tx += s[0];
				acm = acm - dy;
			}
		}
	}
}

void	line(t_fdf *fdf, t_points src, t_points dst)
{
	line_x(fdf, src, dst);
	line_y(fdf, src, dst);
}

void	put_pixel(t_fdf *fdf, t_points p1, t_points p2)
{
	if (p2.color == 0)
	{
		if ((p1.z > 0 || p2.z > 0) && (p1.z < 5 || p2.z < 5))
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, 0xD70D2F);
		else if ((p1.z > 5 || p2.z > 5) && (p1.z < 50 || p2.z < 50))
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, 0xA73F3F);
		else if (p1.z > 50 || p2.z > 50)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, 0xffffff);
		else if (p1.z < 0 || p2.z < 0)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, 0x7B2FDB);
		else
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, 0xfdff00);
	}
	else
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, p1.tx, p1.ty, p2.color);
}
