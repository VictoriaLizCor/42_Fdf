/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/29 21:09:55 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include "../include/fdf.h"
#include <fdf.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
