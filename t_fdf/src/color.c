/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:37:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/20 15:45:33 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//white = 16777215 = 0xffffff
void	int_rgb(t_color *rgb, char *str_color, t_map **map)
{
	int	hex;
	int	len;
	int	i;

	if ((*map)->color_change != 1)
		(*map)->color_change = 1;
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
	rgb->r = ((rgb->rgb >> 16) & 0xFF) / 255.0;
	rgb->g = ((rgb->rgb >> 8) & 0xFF) / 255.0;
	rgb->b = (rgb->rgb & 0xFF) / 255.0;
}
