/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:02:07 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/23 02:54:54 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		more_split(char *str, t_points *points)
{
	char	**split;
	char	*color;

	split = ft_strsplit(str, ',');
	points->z = ft_atoi(split[0]);
	points->tz = ft_atoi(split[0]);
	if (split[1])
	{
		color = ft_strchr(split[1], 'x');
		color++;
		points->color = convert_to_dec(color);
	}
	else
		points->color = 0;
}

t_points	**read_file(int fd, t_fdf *fdf)
{
	t_points	**points;
	char		*line;
	char		**split;
	int			x;
	int			y;

	y = 0;
	points = init_points(fdf);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			points[y][x].x = x;
			points[y][x].y = y;
			points[y][x].tx = x;
			points[y][x].ty = y;
			more_split(*split, &points[y][x]);
			split++;
			x++;
		}
		y++;
	}
	return (points);
}

void		fdf_wh(char *filepath, t_fdf **fdf)
{
	char	*line;
	char	**split;
	int		x;
	int		y;
	int		fd;

	x = 0;
	y = 0;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			split++;
			x++;
		}
		y++;
	}
	(*fdf)->dr_x = x;
	(*fdf)->dr_y = y;
	(*fdf)->rotx = 0;
	(*fdf)->roty = 0;
	close(fd);
}

t_points	**init_points(t_fdf *fdf)
{
	t_points	**points;
	int			x;
	int			y;

	x = 0;
	y = 0;
	points = (t_points**)malloc(sizeof(t_points*) * fdf->dr_y);
	while (y < fdf->dr_y)
	{
		points[y] = (t_points*)malloc(sizeof(t_points) * fdf->dr_x);
		y++;
	}
	return (points);
}
