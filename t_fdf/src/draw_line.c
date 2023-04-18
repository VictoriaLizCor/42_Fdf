/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:53:05 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/18 12:09:37 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp));
	*(unsigned int *)dst = color;
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
	float	denominator;

	line.p0 = p0;
	line.p1 = p1;
	line.dx = (p1.x - p0.x);
	line.dy = (p1.y - p0.y);
	if (fabs(line.dx) > fabs(line.dy))
		denominator = fabs(line.dx);
	else
		denominator = fabs(line.dy);
	line.dx = (line.dx / denominator);
	line.dy = (line.dy / denominator);
	while (denominator > 0)
	{
		pixel_put(data->img, line.p0.x, line.p0.y, line.p0.rgb);
		line.p0.x += line.dx;
		line.p0.y += line.dy;
		denominator--;
	}
}

	// cam->x = 1.48;
	// cam->y = -0.19;