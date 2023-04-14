/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/14 11:42:34 by lilizarr         ###   ########.fr       */
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

void	init_cam(t_cam *cam, int width)
{
	float	t_x;
	float	t_y;

	cam->x = 0.4;
	cam->y = 0.4;
	t_x = (WIN_W - WIN_H) * cos(1) * 0.5;
	t_y = (t_x + WIN_H * 0.5) * sin(1);
	cam->offsetx = (WIN_W - t_x) / 4;
	cam->offsety = (WIN_H - t_y) / 3;
	if (width < 20)
		cam->scale = 30;
	else if (width <= 40)
		cam->scale = 20;
	else if (width <= 210)
		cam->scale = 4;
	else
		cam->scale = 1;
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

void	check_map_data(t_map *map)
{
	int			row;
	int			col;
	int			tmp;
	t_matrix	*m;

	row = 0;
	m = map->matrix;
	printf("%p\n", m);
	while (row < map->y_height)
	{
		col = 0;
		while (col < map->x_width)
		{
			tmp = (row * map->x_width) + col;
			printf("temp %d | (%.2f, %.2f, %.2f, %d) \t %p\n", tmp, m[tmp].y, \
			m[tmp].x, m[tmp].z, m[tmp].rgb, &m[tmp]);
			col++;
		}
		row++;
		printf("\n");
	}
}
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
