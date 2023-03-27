/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:57:55 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/03 22:08:21 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_color	get_color(char map)
{
	if ('1' == map)
		return (rgba(123, 123, 123, 0.5));
	else if ('2' == map)
		return (rgba(255, 255, 255, 0.5));
	else if ('H' == map)
		return (rgba(255, 123, 123, 0.5));
	else if ('R' == map)
		return (rgba(255, 0, 0, 0.5));
	else if ('G' == map)
		return (rgba(0, 255, 0, 0.5));
	else if ('B' == map)
		return (rgba(0, 0, 255, 0.5));
	else if ('Y' == map)
		return (rgba(255, 255, 0, 0.5));
	else
		return (rgba(12, 12, 12, 0.5));
}

static void		render_tile_map(t_cub3d *g, int size, t_vec obj, float step)
{
	t_ivec	iv;

	iv.y = -1;
	while (++iv.y < size)
	{
		obj.x = g->pos.x - 5;
		iv.x = -1;
		while (++iv.x < size)
		{
			if (0 <= obj.x && obj.x < g->map.w &&
				0 <= obj.y && obj.y < g->map.h)
			{
				g_color = get_color(g->map.data[(int)(obj.y)][(int)obj.x]);
				put_pixel(&g->v, iv.x, iv.y);
			}
			obj.x += step;
		}
		obj.y += step;
	}
}

void			render_map(t_cub3d *g)
{
	int		size;
	float	step;
	t_vec	obj;

	size = g->v.h > g->v.w ?
		g->v.w / g->map_size : g->v.h / g->map_size;
	obj = new_vec(g->pos.x - 5, g->pos.y - 5);
	step = ((g->pos.x + 5) - obj.x) / size;
	g_color = rgba(200, 200, 200, 1);
	render_tile_map(g, size, obj, step);
	g_color = rgba(255, 123, 123, 1);
	mid_point_rect(&g->v, new_vec(size / 2, size / 2), size / 15, size / 15);
}
