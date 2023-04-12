/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/12 17:03:21 by lilizarr         ###   ########.fr       */
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
	m->x += cam->offsetx;
	m->y += cam->offsety;
}

t_matrix	perspective(t_matrix m, t_data *data)
{
	int		w;
	int		h;
	t_map	*map;

	map = data->map;
	w = map->x_width;
	h = map->y_height;
	m.x -= (double)(w - 1) * 0.3;
	m.y -= (double)(h - 1) * 0.3;
	m.z -= (double)(map->z_min + map->z_max) * 0.3;
	isometric_projection(&m, data->cam);
	printf("%.2f, %.2f, %.2f, %d) \n", m.y, m.x, \
			m.z, m.rgb);
	return (m);
}

void	draw_line()
{
	
}

void	render(t_data *data, int x, int y)
{
	t_map		*map;
	t_matrix	*m;
	t_matrix	mp;
	int			tmp;

	map = data->map;
	m = map->matrix;
	while (y < map->y_height)
	{
		while (x < map->x_width)
		{
			tmp = y * map->x_width + x;
			mp = perspective(m[tmp], data);
			if (x < map->x_width - 1)
				
			if (y < map->y_height - 1)
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
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
	(*data)->img->img = mlx_new_image(&(*data)->mlx, WIN_W, WIN_H);
	(*data)->img->addr = mlx_get_data_addr(&(*data)->img->img, \
		&(*data)->img->bpp, &(*data)->img->line_length, &(*data)->img->endian);
	(*data)->img->bpp /= 8;
	ft_printf("window: \t%p\n", (*data)->win);
	ft_printf("mouse: \t\t%p\n", (*data)->mouse);
	ft_printf("img: \t\t%p\n", (*data)->img);
	ft_printf("*img: \t\t%p\n\n", &(*data)->img);
	// check_map_data((*data)->map);
	(*data)->cam->x = 0.3;
	(*data)->cam->y = 0.3;
	(*data)->cam->scale = 30;
	(*data)->cam->offsetx = WIN_W / 2;
	(*data)->cam->offsety = WIN_H / 2;
	if (!((*data)->win))
		return (-1);
	return (0);
}
	// check_map_data((*data)->map);