/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:14:50 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/01/22 07:35:42 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../libft/get_next_line.h"

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				tx;
	int				ty;
	int				tz;
	int				color;
}					t_points;

typedef struct		s_fdf
{
	int				win_x;
	int				win_y;
	int				dr_x;
	int				dr_y;
	double			scalexy;
	double			scalez;
	int				sx;
	int				sy;
	int				ex;
	int				ey;
	void			*mlx_ptr;
	void			*win_ptr;
	int				proj;
	double			rotx;
	double			roty;
	t_points		**points;
}					t_fdf;

t_points			**read_file(int fd, t_fdf *fdf);
t_points			*points_new(int x, int y, int z, int color);
void				points_add(t_points **points, t_points *new);
void				fdf_wh(char *filepath, t_fdf **fdf);
t_fdf				*fdf_new(int width, int height, int scalexy, int scalez);
t_points			**init_points(t_fdf *fdf);
void				iso(int *x, int *y, int z);
void				para(int *x, int *y, int z);
void				calc_scale(t_fdf **fdf);
void				iso_app(t_fdf **fdf);
void				para_app(t_fdf **fdf);
void				center_app(t_fdf **fdf);
void				draw(t_fdf *fdf);
void				line(t_fdf *fdf, t_points p1, t_points p2);
char				*ft_strrev(char *t);
int					convert_to_dec(char *str);
int					ft_atoi_base(const char *str, int str_base);
void				init_scale(t_fdf **fdf);
void				x_rotation(t_fdf **fdf, double *rotx, int up);
void				y_rotation(t_fdf **fdf, double *roty, int up);
int					deal_key(int key, t_fdf *fdf);
void				mlx_man(t_fdf *fdf);
void				line(t_fdf *fdf, t_points src, t_points dst);
void				put_pixel(t_fdf *fdf, t_points p1, t_points p2);
int					deal_key2(int key, t_fdf *fdf);
int					deal_key3(int key, t_fdf *fdf);
void				do_work(t_fdf *fdf, int par1, int par2);
void				ft_center(t_fdf **fdf);
#endif
