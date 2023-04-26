/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:12:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/26 14:02:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_pressed(int key, t_data *d)
{
	if (key == ESC_KEY)
		free_data(d, 1);
	if (get_mouse_button)
		printf("mouse");
	return (0);
}

// get_mouse_button mac
int	free_data(t_data *d, int success)
{
	if (d->map)
	{
		free(d->map->matrix);
		free(d->map);
	}
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx && d->img)
		mlx_destroy_image(d->mlx, d->img);
	free(d->img);
	free(d->cam);
	free(d->mouse);
	free(d->title);
	if (!success)
		ft_error("MLX initialization failed.");
	else
		exit(EXIT_SUCCESS);
	return (0);
}
