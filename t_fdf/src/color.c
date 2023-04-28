/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:37:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 11:04:43 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	h_rgb(float v1, float v2, float v3, t_color *c)
{
	c->h = v1;
	c->s = v2;
	c->l = v3;
}

void	hsl_rgb(t_color *c)
{
	float	m;
	float	n;
	float	x;
	t_color	tmp;

	n = c->s * c->l;
	m = c->l - n;
	x = n * (1 - fabs(fmod(c->h / 60.0, 2) - 1));
	if (c->h >= 0 && c->h < 60)
		h_rgb(n, x, 0, &tmp);
	else if (c->h >= 60 && c->h < 120)
		h_rgb(x, n, 0, &tmp);
	else if (c->h >= 120 && c->h < 180)
		h_rgb(0, n, x, &tmp);
	else if (c->h >= 180 && c->h < 240)
		h_rgb(0, x, n, &tmp);
	else if (c->h >= 240 && c->h < 300)
		h_rgb(x, 0, n, &tmp);
	else
		h_rgb(n, 0, x, &tmp);
	c->r = (255 * (tmp.h + m));
	c->g = (255 * (tmp.s + m));
	c->b = (255 * (tmp.l + m));
	c->rgb = ((c->r & 0x0FF) << 16) | ((c->g & 0x0FF) << 8) | (c->b & 0x0FF);
}
// printf("hsl_rgb: %d | %d | %d | %d\n", c->r, c->g, c->b, c->rgb);

void	lerp(t_color c1, t_color c2, t_color *r, float t)
{
	float	t_h;
	float	d;

	d = c2.h - c1.h;
	if (c1.h > c2.h)
	{
		t_h = c2.h;
		c2.h = c1.h;
		c1.h = t_h;
		d = -d;
		t = 1 - t;
	}
	r->h = fabs(c1.h + d * t);
	r->s = c1.s + fabs((c2.s - c1.s) * t);
	r->l = c1.l + fabs((c2.l - c1.l) * t);
	hsl_rgb(r);
}
// printf("r: h:  %.2f | s : %.2f | l: %.2f | d: %.2f\n", r->h, r->s, r->l, d);

void	get_hsl(t_color *c)
{
	float	hue;
	double	min;
	double	max;

	min = find_min((double)c->r / 255, (double)c->g / 255, (double)c->b / 255);
	max = find_max((double)c->r / 255, (double)c->g / 255, (double)c->b / 255);
	if (min == max)
		return ;
	hue = 0;
	c->l = (float)((min + max) / 2);
	if (c->l <= 50)
		c->s = (float)((max - min) / (min + max));
	else
		c->s = (float)((max - min) / (2 - max - min));
	if (max == (float)c->r / 255)
		hue = (c->g - c->b) / (max - min);
	else if (max == (float)c->g / 255)
		hue = 2 + ((float)c->b / 255 - (float)c->r / 255) / (float)(max - min);
	else
		hue = 4 + ((float)c->r / 255 - (float)c->g / 255) / (float)(max - min);
	hue = hue * 60;
	if (hue < 0)
		hue = hue + 360;
	c->h = round(hue);
}

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
			hex = str_color[i] - 'A' + 10;
		rgb->rgb += hex * pow(16, (len - i));
		i--;
	}
	rgb->r = ((rgb->rgb >> 16) & 0xFF);
	rgb->g = ((rgb->rgb >> 8) & 0xFF);
	rgb->b = (rgb->rgb & 0xFF);
	get_hsl(rgb);
}
