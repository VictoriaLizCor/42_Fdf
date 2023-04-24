/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:53:05 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	pixel_put(t_im *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, t_matrix p0, t_matrix p1)
{
	t_line	line;
	float	d;

	line.p0 = p0;
	line.dx = (p1.x - p0.x);
	line.dy = (p1.y - p0.y);
	if (fabs(line.dx) > fabs(line.dy))
		d = fabs(line.dx);
	else
		d = fabs(line.dy);
	line.dx = (line.dx / d);
	line.dy = (line.dy / d);
	while (d > 0)
	{
		if (line.p0.p == 0 && data->map->color_change == 0)
			lerp(line.p0.rgb, p1.rgb, &line.p0.rgb, p1.p / d);
		else if (line.p0.p != 0 && data->map->color_change == 0)
			lerp(line.p0.rgb, p1.rgb, &line.p0.rgb, line.p0.p / d);
		pixel_put(data->img, line.p0.x, line.p0.y, line.p0.rgb.rgb);
		line.p0.x += line.dx;
		line.p0.y += line.dy;
		d--;
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
}
	// printf("%.2f, %.2f, %.2f) \n", m->y, m->x, \
	// 		m->z);

	// printf("**z: %d | %d | %.2f\n", map->z_min, map->z_max, m.z);
	// printf("rgb->intrgb : %d\n", m.rgb.rgb);
	// printf("rgb->r : %d\n", m.rgb.r);
	// printf("rgb->g : %d\n", m.rgb.g);
	// printf("rgb->b : %d\n", m.rgb.b);
	// printf("rgb->h : %d\n", m.rgb.h);

t_matrix	perspective(t_matrix m, t_data *data)
{
	t_cam	*cam;
	t_map	*map;
	float	t_z;

	map = data->map;
	cam = data->cam;
	m.x -= ((m.x - 1.0) / (map->x_max - 1.0)) / map->x_max;
	m.y -= ((m.y - 1.0) / (map->y_max - 1.0)) / map->y_max;
	t_z = m.z;
	if (map->z_max - map->z_min == 0)
		t_z = 0;
	else
	{
		m.z = ((t_z - (float)map->z_min) / \
				(float)(map->z_max - map->z_min)) * cam->z;
	}
	isometric_projection(&m, data->cam);
	m.x += cam->offsetx;
	m.y += cam->offsety;
	return (m);
}
