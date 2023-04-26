/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/26 12:58:14 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	find_max_values(t_data *data, t_matrix *max, int x, int y)
{
	t_map		*map;
	t_matrix	*m;
	t_matrix	mp;
	int			w;

	map = data->map;
	m = map->matrix;
	w = map->x_max;
	*max = perspective(m[0], data);
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			mp = perspective(m[y * w + x], data);
			if (max->x < mp.x)
				max->x = mp.x;
			if (max->y < mp.y)
				max->y = mp.y;
			x++;
		}
		y++;
	}
}

	// printf("lerp_r:\t r:  %d | g : %d | b: %d \n", m.rgb.r, m.rgb.g, m.rgb.b);
	// printf("\t h:  %.2f | s : %.2f | l: %.2f \n", m.rgb.h, m.rgb.s, m.rgb.l);
// printf("%.2f, %.2f, %.2f, %d) \n", m.y, m.x, \
			// m.z, m.rgb);
	// if ((*data).map->color_change == 0)
	// {
	// 	printf("\nc1: r: %d| g: %d | b: %.d \t ", map->c1.r, map->c1.g, 
	// map->c1.b);
	// 	printf("c1: h:  %.2f | s : %.2f | l: %.2f \n", map->c1.h, 
	// map->c1.s, map->c1.l);
	// 	printf("c2: r: %d| g: %d | b: %d \t", map->c2.r, map->c2.g, 
	// map->c2.b);
	// 	printf("c2: h:  %.2f | s : %.2f | l: %.2f \n", map->c2.h, 
	// map->c2.s, map->c2.l);
	// 	lerp(&map->c1, &map->c2, &m.rgb, m.z / map->z_max);
	// 	printf("lerp_r:\t h:  %.2f | s : %.2f | l: %.2f \n", m.rgb.h,
	//  m.rgb.s, m.rgb.l);
	// printf("\nlerp_r:\t h:  %.2f | s : %.2f | l: %.2f \n", m.rgb.h,
	//  m.rgb.s, m.rgb.l);
void	render(t_data *data, int x, int y)
{
	t_map		*map;
	t_matrix	*m;
	t_matrix	mp;
	int			w;

	map = data->map;
	m = map->matrix;
	w = map->x_max;
	clear_image(data->img);
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			mp = perspective(m[y * w + x], data);
			if (x < (map->x_max - 1))
				draw_line(data, mp, perspective(m[y * w + (x + 1)], data));
			if (y < (map->y_max - 1))
				draw_line(data, mp, perspective(m[(y + 1) * w + x], data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	print_onscreen(data);
}
// printf("\nval of z: %.2f | z/max_z:  %.2f\n",
//  m[y * w + x].z, m[y * w + x].p);
// printf("lerp_r:\t r:  %d | g : %d | b: %d \n", 
// m[y * w + x].rgb.r, m[y * w + x].rgb.g, m[y * w + x].rgb.b);
// printf("%.2f, %.2f, %.2f, %d) \n", m[tmp].y, m[tmp].x, 
// m[tmp].z, m[tmp].rgb);

void	init_colors(t_map **m, int x, int y)
{
	t_matrix	*v;

	v = (*m)->matrix;
	if ((*m)->color_change == 0)
	{
		int_rgb(&(*m)->c1, "FF");
		int_rgb(&(*m)->c2, "FF0000");
		while (y < (*m)->y_max)
		{
			x = 0;
			while (x < (*m)->x_max)
			{
				if ((*m)->z_max - (*m)->z_min == 0)
					v[y * (*m)->x_max + x].p = 0;
				else
					v[y * (*m)->x_max + x].p = ((v[y * (*m)->x_max + x].z - \
					(float)(*m)->z_min) / (float)((*m)->z_max - (*m)->z_min));
				lerp((*m)->c1, (*m)->c2, &v[y * (*m)->x_max + x].rgb, v[y * \
				(*m)->x_max + x].p);
				x++;
			}
			y++;
		}
	}
}

void	init_cam(t_cam *cam, t_map *map, t_data *d)
{
	t_matrix	t1;
	t_matrix	t2;

	cam->x = 80 * (M_PI / 180);
	cam->y = 23 * (M_PI / 180);
	cam->z = 1;
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

int	init_render_data(t_data **data, char *file)
{
	(*data)->title = ft_strjoin("42 Fdf | ", file);
	(*data)->mlx = mlx_init();
	if (!((*data)->mlx) || !((*data)->title))
		return (-1);
	(*data)->win = mlx_new_window((*data)->mlx, WIN_W, \
					WIN_H, (*data)->title);
	(*data)->mouse = (t_mouse *)ft_calloc(sizeof(t_mouse), 1);
	(*data)->img = (t_im *)ft_calloc(sizeof(t_im), 1);
	(*data)->cam = (t_cam *)ft_calloc(sizeof(t_cam), 1);
	if (!((*data)->mouse) || !((*data)->img) || !(*data)->win || !(*data)->cam)
		return (-1);
	(*data)->img->img = mlx_new_image((*data)->mlx, WIN_W, WIN_H);
	(*data)->img->addr = mlx_get_data_addr((*data)->img->img, \
		&(*data)->img->bpp, &(*data)->img->line_length, &(*data)->img->endian);
	(*data)->img->bpp /= 8;
	init_cam((*data)->cam, (*data)->map, *data);
	init_colors(&(*data)->map, 0, 0);
	if (!((*data)->win))
		return (-1);
	return (0);
}

	// ft_printf("map: \t\t%p\n", (*data)->map);
	// ft_printf("*matrix: \t%p\n", (*data)->map->matrix);
	// ft_printf("mlx : \t\t%p\n", (*data)->mlx);
	// ft_printf("title : \t%p\n", (*data)->title);
	// ft_printf("window: \t%p\n", (*data)->win);
	// ft_printf("cam: \t\t%p\n", (*data)->cam);
	// ft_printf("mouse: \t\t%p\n", (*data)->mouse);
	// ft_printf("img: \t\t%p\n", (*data)->img);
	// ft_printf("*img: \t\t%p\n\n", &(*data)->img);