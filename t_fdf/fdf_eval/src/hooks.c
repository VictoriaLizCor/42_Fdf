/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:12:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 12:12:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	print_key(int keysym)
{
	if (keysym == ESC_KEY)
		ft_printf("Closing window [key: %d]\n", keysym);
	return (keysym);
}

int	key_pressed(int keysym, t_data *d)
{
	if (print_key(keysym) == ESC_KEY)
		clean_data(d, 1);
	return (0);
}

static void	free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

int	clean_data(t_data *d, int success)
{
	free_ptr(d->title);
	if (d->map)
		free_ptr(d->map->matrix);
	free_ptr(d->map);
	free_ptr(d->cam);
	free_ptr(d->mouse);
	if (d->mlx && d->img)
	{
		mlx_destroy_image(d->mlx, d->img->img);
		free_ptr(d->img);
	}
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	free_ptr(d);
	if (!success)
		ft_error("MLX initialization failed.");
	else
		exit(EXIT_SUCCESS);
	return (0);
}
