/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:33 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/12 15:08:41 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
// to be deleted
# include <string.h>
# include <stdio.h>
# include <limits.h>

// # include "fdf.h"
// # ifdef __APPLE__
// #  include "lib/minilibx_macos/mlx.h"
// # else
// #  include "../lib/minilibx_linux/mlx.h"
// #elif defined _WIN32 || defined _WIN64
//     #include <GL\glut.h>
// # endif
// #ifdef __APPLE__
//     DoSomething();
// #elif _WIN32
//     DoSomethingElse();
// #else
//     GenerateErrorOrIgnore
# ifndef WIN_W
#  define WIN_W 1080
# endif

# ifndef WIN_H
#  define WIN_H 920
# endif

typedef struct s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}					t_cam;

typedef struct s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
}				t_mouse;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_matrix{
	float	x;
	float	y;
	float	z;
	int		rgb;
}				t_matrix;

typedef struct s_line
{
	t_matrix	start;
	t_matrix	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct s_map
{
	int			x_width;
	int			y_height;
	int			z_min;
	int			z_max;
	t_matrix	*matrix;
}				t_map;

typedef struct s_data{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
	t_mouse	*mouse;
	char	*title;
	double	**zbuf;
}				t_data;

/* fdf.c (main)*/
// static int	int_rgb_color(char *str_color);
// static int	read_map(t_map **map, int fd);
// static void	fill_matrix(t_matrix *row, t_map **map, int y, char **row_data);
// static int	get_map_data(t_map **map, int fd, int y);
int			main(int argc, char **argv);
/* render.c */
// void		render;
int			init_render_data(t_data **data, char *file);
void		render(t_data *data, int x, int y);
/* check_error.c */
void		ft_error(char *msg);
void		get_map_size(char **matrix, int *cols);
/* utils.c */
void		ft_free(void **array);
void		check_map_data(t_map *map);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		check_after_string_data(char *str, int ret, int extra);
#endif