/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 12:18:30 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	find_max(double v1, double v2, double v3)
{
	double	max;

	if (v1 >= v2 && v1 >= v3)
		max = v1;
	else if (v2 >= v1 && v2 >= v3)
		max = v2;
	else
		max = v3;
	return (max);
}

double	find_min(double v1, double v2, double v3)
{
	double	min;

	if (v1 <= v2 && v1 <= v3)
		min = v1;
	else if (v2 <= v1 && v2 <= v3)
		min = v2;
	else
		min = v3;
	return (min);
}

void	ft_free(void **array)
{
	int	i;

	i = 0;
	while (*(array + i))
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

void	print_onscreen(t_data	*d)
{
	char	*txt;

	txt = ft_strjoin("File: ", ft_strchr(d->title, 'm'));
	mlx_string_put(d->mlx, d->win, 10, WIN_H - 30, 0x00ffffff, txt);
	free(txt);
}

void	clear_image(t_im *img)
{
	ft_bzero(img->addr, WIN_W * WIN_H * img->bpp);
}
