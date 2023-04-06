/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:33 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/06 16:30:29 by lilizarr         ###   ########.fr       */
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
# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1080
# endif

# ifndef SCREEN_HIGHT
#  define SCREEN_HIGHT 920
# endif

typedef struct s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_matrix{
	int				x;
	int				y;
	int				z;
	int				color;
	// struct s_matrix	*previous;
	// struct s_matrix	*next;
}				t_matrix;

typedef struct s_map
{
	int			x_width;
	int			y_height;
	int			z_min;
	int			z_max;
	t_matrix	**matrix;
}				t_map;

typedef struct s_data{
	void	*xml;
	t_map	*map;
	t_img	*img;
	char	*addr;
	int		line_length;
}				t_data;

/* check_error.c */
void		ft_error(char *msg);
void		get_map_size(char **matrix, int *cols);
void		ft_free(void **array);
/* utils.c */
void		ft_free(void **array);
t_matrix	*last_element(t_matrix *ptr);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		check_after_string_data(char *str, int ret, int extra);
#endif