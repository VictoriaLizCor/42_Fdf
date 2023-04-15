/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:53:05 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/15 16:33:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp));
	*(unsigned int *)dst = color;
	// *(int *)(img->addr + ((x + y * WIN_W) * (img->bpp))) = color;
}

int	ft_abs(float a, float b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

void	draw_line(t_data *data, t_matrix p0, t_matrix p1)
{
	t_line	line;
	float	d;
	int		pxc;

	line.p0 = p0;
	line.p1 = p1;
	line.dx = (p1.x - p0.x);
	line.dy = (p1.y - p0.y);
	if (fabs(line.dx) > fabs(line.dy))
		d = fabs(line.dx) * 10;
	else
		d = fabs(line.dy) * 10;
	line.dx = (line.dx / d);
	line.dy = (line.dy / d);
	while (d > 0)
	{
		pxc = line.p0.rgb;
		if (!(*data).map->color_change)
			pixel_color(&pxc, line.p0, line.p1, data);
		line.p0.x += line.dx;
		line.p0.y += line.dy;
		pixel_put(data->img, p0.x, p0.y, (int)0xFF00);
		pixel_put(data->img, line.p0.x, line.p0.y, pxc);
		// mlx_pixel_put(data->mlx, data->win, round(p0.x), round(p0.y), (int)0xFF00);
		// mlx_pixel_put(data->mlx, data->win, line.p0.x, line.p0.y, pxc);
		d--;
	}
}
