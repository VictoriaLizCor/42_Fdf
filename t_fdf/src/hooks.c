/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:12:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/26 17:32:03 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_pressed(int keysym, t_data *d)
{
	if (keysym == ESC_KEY)
		free_data(d, 1);
	return (0);
}

// get_mouse_button mac
int	free_data(t_data *d, int success)
{
	if (d->map && d->map->matrix)
		free(d->map->matrix);
	if (d->map)
		free(d->map);
	if (d->cam)
		free(d->cam);
	if (d->mouse)
		free(d->mouse);
	if (d->title)
		free(d->title);
	if (d->mlx && d->img)
		mlx_destroy_image(d->mlx, d->img->img);
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->img)
		free(d->img);
	if (d->mlx)
		free(d->mlx);
	if (d)
		free(d);
	if (!success)
		ft_error("MLX initialization failed.");
	else
		exit(EXIT_SUCCESS);
	return (0);
}
