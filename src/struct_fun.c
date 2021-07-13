/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:19:51 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 07:08:53 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_points	*points_new(int x, int y, int z, int color)
{
	t_points	*points;

	if (!(points = (t_points *)malloc(sizeof(*points))))
		return (NULL);
	points->x = x;
	points->y = y;
	points->tx = x;
	points->ty = y;
	points->tz = z;
	points->z = z;
	points->color = color;
	return (points);
}

t_fdf		*fdf_new(int win_x, int win_y, int scalexy, int scalez)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(*fdf))))
		return (NULL);
	fdf->win_x = win_x;
	fdf->win_y = win_y;
	fdf->scalexy = scalexy;
	fdf->scalez = scalez;
	fdf->proj = 1;
	return (fdf);
}
