/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:37:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/21 14:21:59 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//white = 16777215 = 0xffffff
void	get_hsl(t_color *c)
{
	float	hue;
	float	min;
	float	max;

	min = find_min((float)c->r / 255, (float)c->g / 255, (float)c->b / 255);
	max = find_max((float)c->r / 255, (float)c->g / 255, (float)c->b / 255);
	printf("rgb: %.2f | %.2f | %.2f\n\n", (float)c->r / 255, \
	(float)c->g / 255, (float)c->b / 255);
	if (min == max)
		return ;
	hue = 0;
	c->l = round ((min + max) / 2 * 100);
	if (c->l <= 0.5)
		c->s = (max - min) / (min + max);
	else
		c->s = round((max - min) / (2 - min - max) * 100);
	printf("rgb: %.2f | %.2f| %d\n", min, max, c->h);
	if (max == (float)c->r / 255)
		hue = (c->g - c->b) / (max - min);
	else if (max == (float)c->g / 255)
		hue = 2 + ((float)c->b / 255 - (float)c->r / 255) / (max - min);
	else
		hue = 4 + ((float)c->r / 255 - (float)c->g / 255) / (max - min);
	hue = hue * 60;
	if (hue < 0)
		hue = hue + 360;
	c->h = round(hue);
	printf("hsl: %d | %d | %d\n", c->h, c->s, c->l);
}

// function lerpRGB(color1, color2, t) {
// 	let color = {};
// 	color.r = color1.r + ((color2.r - color1.r) * t);
// 	color.g = color1.g + ((color2.g - color1.g) * t);
// 	color.b = color1.b + ((color2.b - color1.b) * t);
// 	return color;
// }

void	int_rgb(t_color *rgb, char *str_color)
{
	int	hex;
	int	len;
	int	i;

	len = (int)ft_strlen(str_color) - 1;
	i = len;
	rgb->rgb = 0;
	while (i > -1)
	{
		hex = str_color[i] - '0';
		if (!ft_isdigit(str_color[i]))
			hex = str_color[len] - 'A' + 10;
		rgb->rgb += hex * pow(16, (len - i));
		i--;
	}
	rgb->r = ((rgb->rgb >> 16) & 0xFF);
	rgb->g = ((rgb->rgb >> 8) & 0xFF);
	rgb->b = (rgb->rgb & 0xFF);
	printf("int_rgb: %d | %d | %d\n\n", rgb->r, rgb->g, rgb->b);
	get_hsl(rgb);
}

void	pixel_color(int *color, t_matrix p0, t_map *m, t_cam *c)
{
	float	t_x;
	float	t_y;
	float	t_z;

	t_x = cos(c->y) * (float)m->max_val + sin(c->y) * m->z_max;
	t_z = -sin(c->y) * t_x + cos(c->y) * m->z_max;
	t_y = cos(c->x) * (float)m->max_val - sin(c->x) * t_z;
	t_x = (t_x * c->scale) + c->offsetx;
	t_y = (t_y * c->scale) + c->offsety;
	*color = 0x00FFFF;
	// printf("x = %.2f | y = %.2f\n", c->x * (180 / 3.1416), c->y * (180 /3.1416));
	// // *color = ((int)(p0.z / t_z * 1000)) * (int)0x556B2F;
	// // ft_printf(" %d \t | %d\n", (int)0x556B2F, (int)(p0.z / t_z) * (int)0x556B2F);
	// ft_printf("%d \n", (int)0xFFFFFF - ((int)(((p1.z - p0.z) / t_z))));
	// *color = (int)0xFFFFFF - ((int)((p.z / t_z)));
}
