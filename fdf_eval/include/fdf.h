/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:33 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 12:32:27 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "hook_key.h"
# include <math.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

# ifndef WIN_W
#  define WIN_W 1080
# endif

# ifndef WIN_H
#  define WIN_H 920
# endif

# ifndef M_PI
#  define M_PI 3.14159265358
# endif

typedef struct s_cam
{
	float		offsetx;
	float		offsety;
	float		x;
	float		y;
	float		z;
	float		scale;
	double		*matrix;
}					t_cam;

typedef struct s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct s_im
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_im;

typedef struct color{
	int		r;
	int		g;
	int		b;
	float	h;
	float	l;
	float	s;
	int		rgb;
}				t_color;

typedef struct s_matrix{
	double		x;
	double		y;
	double		z;
	float		p;
	t_color		rgb;
}				t_matrix;

typedef struct s_line
{
	t_matrix	p0;
	double		dx;
	double		dy;
}				t_line;

typedef struct s_map
{
	int			x_max;
	int			y_max;
	double		z_min;
	double		z_max;
	double		max_val;
	int			color_change;
	t_color		c1;
	t_color		c2;
	t_matrix	*matrix;
}				t_map;

typedef struct s_data{
	void		*mlx;
	void		*win;
	t_im		*img;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	char		*title;
	double		**zbuf;
}				t_data;

/* fdf.c (main)*/
int			main(int argc, char **argv);
/* render.c */
// void		render;
void		find_max_values(t_data *data, t_matrix *max, int x, int y);
void		render(t_data *data, int x, int y);
void		init_colors(t_map **m, int x, int y);
void		init_cam(t_cam *cam, t_map *map, t_data *d);
int			init_render_data(t_data **data, char *file);
/* draw_line.c */
void		pixel_put(t_im *img, int x, int y, int color);
void		draw_line(t_data *data, t_matrix p0, t_matrix p1);
t_matrix	perspective(t_matrix m, t_data *data);
/* color.c */
void		lerp(t_color c1, t_color c2, t_color *r, float t);
void		int_rgb(t_color *rgb, char *str_color);
/* hooks.c*/
int			clean_data(t_data *d, int success);
int			key_pressed(int key, t_data *d);
/* check_error.c */
void		ft_error(char *msg);
void		get_map_size(char **matrix, int *cols);
/* utils.c */
void		ft_free(void **array);
void		print_onscreen(t_data *d);
void		clear_image(t_im *img);
double		find_max(double v1, double v2, double v3);
double		find_min(double v1, double v2, double v3);
#endif