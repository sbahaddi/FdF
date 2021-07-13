/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 02:29:27 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 07:37:03 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key3(int key, t_fdf *fdf)
{
	if (key == 6)
	{
		do_work(fdf, 2, 0);
		return (1);
	}
	else if (key == 1)
	{
		do_work(fdf, 0, 1);
		return (1);
	}
	else if (key == 0)
	{
		do_work(fdf, 0, 2);
		return (1);
	}
	else if (key == 15)
	{
		init_scale(&fdf);
		ft_center(&fdf);
		do_work(fdf, 3, 3);
		return (0);
	}
	do_work(fdf, 0, 0);
	return (0);
}

int		deal_key2(int key, t_fdf *fdf)
{
	if (key == 121)
		fdf->scalez = fdf->scalez - 1;
	else if (key == 34)
	{
		x_rotation(&fdf, &fdf->rotx, 3);
		y_rotation(&fdf, &(fdf->roty), 3);
		fdf->proj = 1;
	}
	else if (key == 35)
	{
		x_rotation(&fdf, &fdf->rotx, 3);
		y_rotation(&fdf, &(fdf->roty), 3);
		fdf->proj = 2;
	}
	else if (key == 7)
	{
		do_work(fdf, 1, 0);
		return (0);
	}
	return (deal_key3(key, fdf));
}

int		deal_key(int key, t_fdf *fdf)
{
	if (key == 126)
	{
		fdf->sy = fdf->sy - 10;
	}
	else if (key == 125)
		fdf->sy = fdf->sy + 10;
	else if (key == 69)
	{
		fdf->scalexy *= 1.2;
		fdf->scalez *= 1.2;
	}
	else if (key == 78)
	{
		fdf->scalexy /= 1.2;
		fdf->scalez /= 1.2;
	}
	else if (key == 124)
		fdf->sx = fdf->sx + 10;
	else if (key == 123)
		fdf->sx = fdf->sx - 10;
	else if (key == 53)
		exit(0);
	else if (key == 116)
		fdf->scalez = fdf->scalez + 1;
	return (deal_key2(key, fdf));
}
