/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/21 12:13:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void find_max_values(t_data *data, t_matrix *max, int x, int y)
{
	t_map		*map;
	t_matrix	*m;
	t_matrix	mp;
	int			w;

	map = data->map;
	m = map->matrix;
	w = map->x_width;
	*max = perspective(m[0], data);
	while (y < map->y_height)
	{
		x = 0;
		while (x < map->x_width)
		{
			mp = perspective(m[y * w + x], data);
			if(max->x < mp.x)
				max->x = mp.x;
			if(max->y < mp.y)
				max->y = mp.y;
			x++;
		}
		y++;
	}
}

// m->z = sin(cam->x) * (m->y) + cos(cam->x) * (m->z);
static	void	isometric_projection(t_matrix *m, t_cam *cam)
{
	m->x = cos(cam->y) * (m->x) + sin(cam->y) * (m->z);
	m->z = -sin(cam->y) * (m->x) + cos(cam->y) * (m->z);
	m->y = cos(cam->x) * (m->y) - sin(cam->x) * (m->z);
	m->x *= cam->scale;
	m->y *= cam->scale;
	// printf("%.2f, %.2f, %.2f) \n", m->y, m->x, \
	// 		m->z);
}

t_matrix	perspective(t_matrix m, t_data *data)
{
	int		w;
	int		h;
	t_cam	*cam;
	t_map	*map;

	map = data->map;
	cam = data->cam;
	w = map->x_width;
	h = map->y_height;
	m.x -= ((m.x - 1.0) / (w - 1.0)) / w;
	m.y -= ((m.y - 1.0) / (h - 1.0)) / h;
	// printf("\nx: %d |%.2f\n", w, m.x);
	// printf("y: %d | %.2f\n", h, m.y);
	// printf("before: %.2f | %.2f \n", m.z, m.z / map->z_max);
	// printf("**z: %d | %d | %.2f\n", map->z_min, map->z_max, m.z);
	// printf("rgb->intrgb : %d\n", m.rgb.rgb);
	// printf("rgb->r : %d\n", m.rgb.r);
	// printf("rgb->g : %d\n", m.rgb.g);
	// printf("rgb->b : %d\n", m.rgb.b);
	// printf("rgb->h : %d\n", m.rgb.h);
	if ((*data).map->color_change == 0)
	{
		
	}
	if (map->z_max - map->z_min == 0)
		m.z = 0;
	else
		m.z = ((m.z - (float)map->z_min) / (float)(map->z_max - map->z_min)) * \
				cam->z;
	isometric_projection(&m, data->cam);
	m.x += cam->offsetx;
	m.y += cam->offsety;
	return (m);
}
// printf("%.2f, %.2f, %.2f, %d) \n", m.y, m.x, \
			// m.z, m.rgb);

void	render(t_data *data, int x, int y)
{
	t_map		*map;
	t_matrix	*m;
	t_matrix	mp;
	int			w;

	map = data->map;
	m = map->matrix;
	w = map->x_width;
	clear_image(data->img);
	while (y < map->y_height)
	{
		x = 0;
		while (x < map->x_width)
		{
			mp = perspective(m[y * w + x], data);
			if (x < (map->x_width - 1))
				draw_line(data, mp, perspective(m[y * w + (x + 1)], data));
			if (y < (map->y_height - 1))
				draw_line(data, mp, perspective(m[(y + 1) * w + x], data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	print_onscreen(data);
}
// printf("%.2f, %.2f, %.2f, %d) \n", m[tmp].y, m[tmp].x, \
// m[tmp].z, m[tmp].rgb);

void	init_cam(t_cam *cam, t_map *map, t_data *d)
{
	t_matrix	t1;
	t_matrix	t2;

	cam->x = 80 * (M_PI / 180);
	cam->y = 23 * (M_PI / 180);
	cam->z = 3;
	if (map->max_val <= 50)
		cam->scale = (float)WIN_W / (map->max_val * 2);
	else if (map->max_val < 70)
		cam->scale = (float)WIN_W / (map->max_val);
	else if (map->max_val < 250)
		cam->scale = 5 - (float)map->max_val * 0.01;
	else
		cam->scale = 1.5;
	t1 = perspective(d->map->matrix[0], d);
	find_max_values(d, &t2, 0, 0);
	cam->offsetx = ((float)WIN_W * 0.5) - ((t2.x - t1.x) / 2);
	cam->offsety = ((float)WIN_H * 0.4) - ((t2.y - t1.y) / 2);
}
