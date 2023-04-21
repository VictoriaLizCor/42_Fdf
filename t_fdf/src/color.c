/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:37:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/21 17:40:15 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// //white = 16777215 = 0xffffff
// void	lerp_rgb (t_color *c1, t_color *c2, float t)
// {
// 	float	h;
// 	float	d;

// 	d = c2->h - c1->h;
// 	if (c1->h > c2->h)
// 	{
// 		var h3 = c2->h2;
// 		c2->h = c1->h;
// 		c1->h = h3;
// 		d = -d;
// 		t = 1 - t;
// 	}
// 	if (d > 0.5)
// 	{
// 		c1->h = c1->h + 1;
// 		h = ( c1->h + t * (c2->h - c1->h) ) % 1;
// 	}
// 	if (d <= 0.5)
// 	{
// 		h = c1->h + t * d
// 	}
// 	// return new ColorHSV
//     // (
//     //     h,            // H
//     //     a.s + t * (b.s-a.s),    // S
//     //     a.v + t * (b.v-a.v),    // V
//     //     a.a + t * (b.a-a.a)    // A
//     // );
// }

float	h_rgb(float v1, float v2, float vH)
{
	if (vH < 0)
		vH += 1;
	if (vH > 1)
		vH -= 1;
	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1)
		return (v2);
	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return (v1);
}

void	hsl_rgb(t_color *c)
{
	float	v1;
	float	v2;

	if (c->h == 0)
	{
		c->r = (c->l * 255);
		c->g = (c->l * 255);
		c->b = (c->l * 255);
		return ;
	}
	else
	{
		if (c->l < 0.5)
			v2 = (c->l * (1 + c->s));
		else
			v2 = ((c->l + c->s) - (c->l * c->s));
		v1 = 2 * c->l - v2;
	}
		c->r = (int)round(255 * h_rgb(v1, v2, c->h + (1.0f / 3)));
		c->g = (int)round(255 * h_rgb(v1, v2, c->h));
		c->b = (int)round(255 * h_rgb(v1, v2, c->h - (1.0f / 3)));
}

void	lerp(t_color *c1, t_color *c2, t_color *r, float t)
{
	float	t_h;
	float	d;

	d = c2->h - c1->h;
	if (c1->h > c2->h)
	{
		t_h = c2->h;
		c2->h = c1->h;
		c1->h = t_h;
		d = -d;
		t = 1 - t;
	}
	if (d > 0.5)
	{
		c1->h = c1->h + 1;
		r->h = c1->h + (c2->h - c1->h) * t;
	}
	else
		r->h = c1->h + d * t;
	r->s = c1->s + (c2->s - c1->s) * t;
	r->l = c1->l + (c2->l - c1->l) * t;
	hsl_rgb(r);
}

void	get_hsl(t_color *c)
{
	float	hue;
	float	min;
	float	max;

	min = find_min((float)c->r / 255, (float)c->g / 255, (float)c->b / 255);
	max = find_max((float)c->r / 255, (float)c->g / 255, (float)c->b / 255);
	printf("rgb: %.2f | %.2f | %.2f\n", (float)c->r / 255, \
	(float)c->g / 255, (float)c->b / 255);
	if (min == max)
		return ;
	hue = 0;
	c->l = (min + max) / 2;
	if (c->l <= 50)
		c->s = (max - min) / (min + max);
	else
		c->s = (max - min) / (2 - max - min);
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
	printf("hsl: %.2f | %.2f | %.2f\n", c->h, c->s, c->l);
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
			hex = str_color[len] - 'A' + 10;
		rgb->rgb += hex * pow(16, (len - i));
		i--;
	}
	rgb->r = ((rgb->rgb >> 16) & 0xFF);
	rgb->g = ((rgb->rgb >> 8) & 0xFF);
	rgb->b = (rgb->rgb & 0xFF);
	printf("int_rgb: %d | %d | %d\n", rgb->r, rgb->g, rgb->b);
	get_hsl(rgb);
}

