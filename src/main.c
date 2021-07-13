/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:12:01 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/23 02:59:20 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_man(t_fdf *fdf)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "MOVE : UP, DOWN, LEFT, RIGT KEYS";
	str2 = "Z : PAGE UP, PAGE DOWN";
	str3 = "ROTATION X : Z, X";
	str4 = "ROTATION Y : A, S";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 2, 0xffffff, str1);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 25, 0xffffff, str2);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 50, 0xffffff, "ZOOM : +, -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 75, 0xffffff, str3);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 100, 0xffffff, str4);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 125, 0xffffff, "ISO : I");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 150, 0xffffff, "PARA : P");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 2, 175, 0xffffff, "RESET : R");
}

t_fdf	*start(char *filepath)
{
	t_points	**points;
	t_fdf		*fdf;
	int			fd;

	fdf = fdf_new(1000, 1000, 1, 1);
	fdf_wh(filepath, &fdf);
	if ((fd = open(filepath, O_RDONLY)) < 0)
		return (NULL);
	points = read_file(fd, fdf);
	close(fd);
	fdf->points = points;
	return (fdf);
}

void	ft_center(t_fdf **fdf)
{
	t_points	**points;

	points = (*fdf)->points;
	(*fdf)->sx = 400;
	(*fdf)->sy = 400;
}

void	do_work(t_fdf *fdf, int par1, int par2)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_man(fdf);
	calc_scale(&fdf);
	x_rotation(&fdf, &(fdf->rotx), par1);
	y_rotation(&fdf, &(fdf->roty), par2);
	if (fdf->proj == 1)
		iso_app(&fdf);
	else
		para_app(&fdf);
	center_app(&fdf);
	draw(fdf);
}

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	int			x;
	int			y;

	y = 0;
	x = 0;
	if (argc != 2)
	{
		ft_putstr("You did not pass the right number of arguments.\n");
		ft_putstr("Usage: ./fdf file.fdf\n");
		return (0);
	}
	if (!(fdf = start(argv[1])))
	{
		ft_putstr("File Error\n");
		return (0);
	}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_x, fdf->win_y, "test");
	init_scale(&fdf);
	ft_center(&fdf);
	do_work(fdf, 0, 0);
	mlx_hook(fdf->win_ptr, 2, 1, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
