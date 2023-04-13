/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/13 17:38:36 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	isometric_projection(t_matrix *m, t_cam *cam)
{
	m->x = cos(cam->y) * (m->x) + sin(cam->y) * (m->z);
	m->z = -sin(cam->y) * (m->x) + cos(cam->y) * (m->z);
	m->y = cos(cam->x) * (m->y) - sin(cam->x) * (m->z);
	m->z = sin(cam->x) * (m->y) + cos(cam->x) * (m->z);
	m->x *= cam->scale;
	m->y *= cam->scale;
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
	m.z -= (m.z - (float)map->z_min) / (float)(map->z_max - map->z_min);
	isometric_projection(&m, data->cam);
	m.x += cam->offsetx;
	m.y += cam->offsety;
	return (m);
}
// printf("%.2f, %.2f, %.2f, %d) \n", m.y, m.x, \
			// m.z, m.rgb);

void	draw_line(t_data *data, t_matrix p0, t_matrix p1)
{
	t_line	line;
	float	d;

	line.p0 = p0;
	line.p1 = p1;
	line.dx = (p1.x - p0.x);
	line.dy = (p1.y - p0.y);
	if (fabs(line.dx) > fabs(line.dy))
		d = fabs(line.dx);
	else
		d = fabs(line.dy);
	line.dx = (line.dx / d) * 0.1;
	line.dy = (line.dy / d) * 0.1;;
	// printf("x = %d | y = %d\n", (int)(line.p0.x), (int)(line.p1.y - line.p0.y));
	// while (1)
	while (round(line.p1.y - line.p0.y) || round(line.p1.x - line.p0.x))
	{
		mlx_pixel_put(data->mlx, data->win, line.p0.x, line.p0.y, line.p0.rgb);
		line.p0.x += line.dx;
		line.p0.y += line.dy;
		// if (line.p0.x > line.p1.x || line.p0.y > line.p1.y)
		// 	break ;
	}
}

		// printf("x0 = %d | y0 = %d\n", (int)(line.p0.x), (int)(line.p0.y));
		// printf("x1 = %.2f | y1 = %.2f\n", (line.p1.x), (line.p1.y));
		// printf("0 = %.2f | 0 = %.2f\n", (p0.x), (p0.y));
		// printf("1 = %.2f | 1 = %.2f\n", (p1.x), (p1.y));
		// printf("dx = %.2f | dy = %.2f\n\n", line.dx, (line.dy));

void	clear_image(t_img *img)
{
	ft_bzero(img->addr, WIN_W * WIN_H * img->bpp);
}

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
			{
				ft_printf("\t\t\t\tx = %d | y= %d\n", x, y);
				draw_line(data, mp, perspective(m[y * w + (x + 1)], data));
			}
			if (y < (map->y_height - 1))
			{
				draw_line(data, mp, perspective(m[(y + 1) * w + x], data));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
// printf("%.2f, %.2f, %.2f, %d) \n", m[tmp].y, m[tmp].x, \
// m[tmp].z, m[tmp].rgb);

int	init_render_data(t_data **data, char *file)
{
	ft_printf("map: \t\t%p\n", (*data)->map);
	ft_printf("*matrix: \t%p\n", *(*data)->map->matrix);
	// check_map_data((*data)->map);
	(*data)->title = ft_strjoin("42 Fdf | ", file);
	(*data)->mlx = mlx_init();
	if (!((*data)->mlx))
		return (-1);
	ft_printf("mlx : \t\t%p\n\n", (*data)->mlx);
	ft_printf("window: \t%p\n", (*data)->win);
	ft_printf("mouse: \t\t%p\n", (*data)->mouse);
	ft_printf("img: \t\t%p\n\n", (*data)->img);
	(*data)->win = mlx_new_window((*data)->mlx, WIN_W, \
					WIN_H, (*data)->title);
	(*data)->mouse = (t_mouse *)ft_calloc(sizeof(t_mouse), 1);
	(*data)->img = (t_img *)ft_calloc(sizeof(t_img), 1);
	(*data)->cam = (t_cam *)ft_calloc(sizeof(t_cam), 1);
	ft_printf("window: \t%p\n", (*data)->win);
	ft_printf("mouse: \t\t%p\n", (*data)->mouse);
	ft_printf("img: \t\t%p\n", (*data)->img);
	ft_printf("*img: \t\t%p\n\n", &(*data)->img);
	if (!((*data)->mouse) || !((*data)->img) || !((*data)->win))
		return (-1);
	(*data)->img->img = mlx_new_image((*data)->mlx, WIN_W, WIN_H);
	(*data)->img->addr = mlx_get_data_addr((*data)->img->img, \
		&(*data)->img->bpp, &(*data)->img->line_length, &(*data)->img->endian);
	(*data)->img->bpp /= 8;
	ft_printf("window: \t%p\n", (*data)->win);
	ft_printf("mouse: \t\t%p\n", (*data)->mouse);
	ft_printf("img: \t\t%p\n", (*data)->img);
	ft_printf("*img: \t\t%p\n\n", &(*data)->img);
	// check_map_data((*data)->map);
	(*data)->cam->x = 0.4;
	(*data)->cam->y = 0.4;
	(*data)->cam->scale = 30;
	(*data)->cam->offsetx =  ((WIN_W - (WIN_W * 0.5)) * 0.5);
	(*data)->cam->offsety = ((WIN_H - (WIN_H * 0.5))* 0.5);
	if (!((*data)->win))
		return (-1);
	return (0);
}
	// check_map_data((*data)->map);
// 	m->x = cos(cam->y) * (m->x) + sin(cam->y) * (m->z);
// 	m->z = -sin(cam->y) * (m->x) + cos(cam->y) * (m->z);
// 	m->y = cos(cam->x) * (m->y) - sin(cam->x) * (m->z);