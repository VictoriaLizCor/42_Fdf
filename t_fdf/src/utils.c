/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/17 17:54:13 by lilizarr         ###   ########.fr       */
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

	// cam->x = 1.4;
	// cam->y = 0.4;
	// cam->x = 0.1;
	// cam->y = 1.55;
// cam->x = 45 * (M_PI / 180);
// 	cam->y = 9 * (M_PI / 180);
void	init_cam(t_cam *cam, t_map *map)
{
	float	t_x;
	float	t_y;
	float	t_z;
	float	t_x1;
	float	t_y1;

cam->x = 45 * (M_PI / 180);
	cam->y = 9 * (M_PI / 180);
	if (map->max_val <= 50)
		cam->scale = map->max_val - ((float)map->max_val * 0.6);
	else if (map->max_val < 60)
		cam->scale = map->max_val - ((float)map->max_val * 0.5);
	else if (map->max_val <= 250)
		cam->scale = 5 - (float)map->max_val * 0.01;
	else
		cam->scale = 1.2;
	t_x = (cos(cam->x) * (float)map->x_width) + (sin(cam->x) * map->z_max);
	t_z = (-sin(cam->x) * t_x) + (cos(cam->x) * map->z_max);
	t_y = (cos(cam->y) * (float)map->y_height) - (sin(cam->y) * t_z);
	t_x1 = (cos(cam->x) + sin(cam->x));
	t_z = -sin(cam->x) * t_x1 + cos(cam->y);
	t_y1 = cos(cam->y) - (sin(cam->y) * t_z);
	cam->offsetx = ((float)WIN_W * 0.5) - (((t_x - t_x1) * 0.4)) * cam->scale;
	cam->offsety = ((float)WIN_H * 0.5) - (((t_y - t_y1) * 0.4)) * cam->scale;
}

// x_max = 802.82 | x0 = 581.49 | p = 0.72
// y_max = 665.51 | y0 = 626.63 | p = 0.94
// z_max = -10.32 | z0 = -8.16 | p = 0.79
void	pixel_color(int *color, t_matrix p0, t_map *m, t_cam *c)
{
	float	t_x;
	float	t_y;
	float	t_z;

	t_x = cos(c->y) * (float)m->x_width + sin(c->y) * m->z_max;
	t_z = -sin(c->y) * t_x + cos(c->y) * m->z_max;
	t_y = cos(c->x) * (float)m->y_height - sin(c->x) * t_z;
	t_x = (t_x * c->scale) + c->offsetx;
	t_y = (t_y * c->scale) + c->offsety;
	// printf("x_max = %.2f | x0 = %.2f | p = %.2f\n", t_x, p0.x, p0.x / t_x);
	// printf("y_max = %.2f | y0 = %.2f | p = %.2f\n", t_y, p0.y, p0.y / t_y);
	// printf("z_max = %.2f | z0 = %.2f | p = %.2f\n", t_z, p0.z, p0.z / t_z);
	*color = 0xFFFFFF;
	// printf("x = %.2f | y = %.2f\n", c->x * (180 / 3.1416), c->y * (180 / 45 * 3.1416));
	// // *color = ((int)(p0.z / t_z * 1000)) * (int)0x556B2F;
	// // ft_printf(" %d \t | %d\n", (int)0x556B2F, (int)(p0.z / t_z) * (int)0x556B2F);
	// printf("%.2f | %d\n", c->scale, m->max_val);
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
