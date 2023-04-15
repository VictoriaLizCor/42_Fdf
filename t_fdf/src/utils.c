/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/15 11:45:19 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include "../include/fdf.h"
#include <fdf.h>

void	ft_free(void **array)
{
	int	i;

	i = 0;
	while (*(array + i))
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

void	init_cam(t_cam *cam, t_map *map)
{
	float	t_x;
	float	t_y;
	float	t_z;
	float	t_x1;
	float	t_y1;

	cam->x = 0.5;
	cam->y = 0.5;
	if (map->x_width < 20)
		cam->scale = 30 - ((float)map->x_width / 5);
	else if (map->x_width <= 50)
		cam->scale = 20 - ((float)map->x_width / 5);
	else if (map->x_width <= 200)
		cam->scale = ((float)map->x_width / (float)map->y_height) * 2;
	else
		cam->scale = 2;
	t_x = (cos(1) * (float)map->x_width) + (sin(1) * map->z_max);
	t_z = (-sin(1) * t_x) + (cos(1) * map->z_max);
	t_y = (cos(1) * (float)map->y_height) - (sin(1) * t_z);
	t_x1 = (cos(1) + sin(1));
	t_z = -sin(1) * t_x1 + cos(1);
	t_y1 = cos(1) - ((sin(1) * t_z));
	cam->offsetx = ((float)WIN_W * 0.5) - (((t_x - t_x1) / 2) * cam->scale);
	cam->offsety = ((float)WIN_H * 0.4) - (((t_y - t_y1) / 2) * cam->scale);
}

void	pixel_color(int *color, t_matrix p0, t_matrix p1, t_data *d)
{
	float	t_x;
	float	t_y;
	float	t_z;
	t_cam	*c;
	int		z;

	// c = (*d)->cam;
	// t_x = (cos(c->y) * (float)map->x_width) + (sin(c->y) * map->z_max);
	// t_z = (-sin(c->y) * t_x) + (cos(c->y) * map->z_max);
	// t_y = (cos(1) * (float)map->y_height) - (sin(1) * t_z);
	z = (int)0xFFFFFF - p0.rgb;
	color = (int)0xFFFFFF;
	// ft_printf("z %d\n", z);
	// *color = *color - (int)((p1.z - p0.z) / (*d).map->z_max * (int)0x556B2F);
	// *color = *color - (int)((p1.z - p0.z) / t_z * (int)0x556B2F);
	// ft_printf("-%d \t", (int)((p1.z - p0.z) / t_z * (int)0x556B2F));
	// ft_printf("%d \n", (int)0xFFFFFF - ((int)(((p1.z - p0.z) / t_z))));
	// *color = (int)0xFFFFFF - ((int)((p.z / t_z)));
}

void	print_onscreen(t_data	*d)
{
	char	*txt;

	txt = ft_strjoin("File: ", ft_strchr(d->title, 'm'));
	mlx_string_put(d->mlx, d->win, 10, WIN_H - 30, 0x00ffffff, txt);
	free(txt);
}

void	clear_image(t_img *img)
{
	ft_bzero(img->addr, WIN_W * WIN_H * img->bpp);
}

// void	check_map_data(t_map *map)
// {
// 	int			row;
// 	int			col;
// 	int			tmp;
// 	t_matrix	*m;

// 	row = 0;
// 	m = map->matrix;
// 	printf("%p\n", m);
// 	while (row < map->y_height)
// 	{
// 		col = 0;
// 		while (col < map->x_width)
// 		{
// 			tmp = (row * map->x_width) + col;
// 			printf("temp %d | (%.2f, %.2f, %.2f, %d) \t %p\n", tmp, m[tmp].y, \
// 			m[tmp].x, m[tmp].z, m[tmp].rgb, &m[tmp]);
// 			col++;
// 		}
// 		row++;
// 		printf("\n");
// 	}
// }
	// while(row < map->y_height * map->x_width)
	// {
	// 	ft_printf("(%d, %d, %d, %d) \t %p\n", m[row].y, m[row].x, \
	// 		m[row].z, m[row].rgb, &m[row]);
	// 	row++;
	// }
	// tmp = (row * map->x_width) + col;
	// 		printf("temp %d |   (%.2f, %.2f, %.2f, %d) \t %p\n", tmp, (m+tmp)->y, (m + tmp)->x, \
	// 		(m+tmp)->z, (m+tmp)->rgb, *(m+tmp));
	// 		col++;

// void	check_after_string_data(char *str, int ret, int extra)
// {
// 	int		i;
// 	char	*buf;

// 	if (*str)
// 	{
// 		i = 0;
// 		buf = str;
// 		while (i < ret + extra)
// 		{
// 			if (!ft_strchr("\t\n\r\v\f", buf[i]))
// 				ft_printf("{ %c }",*(buf + i));
// 			else
// 				ft_printf("( %d )", *(buf + i));
// 			i++;
// 		}
// 		ft_printf("| %d\n", ret);
// 	}
// 	else
// 		ft_printf("\n ** null \n");
// }
