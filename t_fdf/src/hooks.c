/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:12:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 11:15:04 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	print_key(int keysym)
{
	if (keysym == ESC_KEY)
		ft_printf("Closing window[key :%d]\n", keysym);
	return (keysym);
}

int	key_pressed(int keysym, t_data *d)
{
	if (print_key(keysym) == ESC_KEY)
		clean_data(d, 1);
	return (0);
}

int	mouse_pressed(int keysym, t_data *d)
{
	if (keysym == MOUSE_LEFT_KEY)
		print_key(keysym);
	if (keysym == MOUSE_RIGHT_KEY)
		print_key(keysym);
	if (keysym == MOUSE_SCROLL_UP)
		print_key(keysym);
	if (keysym == MOUSE_SCROLL_DOWN)
		print_key(keysym);
	return (0);
}

int	mouse_released(int keysym, t_data *d)
{
	int	cpy;

	cpy = 10 + keysym;
	if (keysym == MOUSE_LEFT_KEY)
		print_key(cpy);
	if (keysym == MOUSE_RIGHT_KEY)
		print_key(cpy);
	if (keysym == MOUSE_SCROLL_UP)
		print_key(cpy);
	if (keysym == MOUSE_SCROLL_DOWN)
		print_key(cpy);
	return (0);
}

// get_mouse_button mac
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
// ft_bzero(img->addr, WIN_W * WIN_H * img->bpp);
// int	clean_data(t_data *d, int success)
// {
// 	if (d->map && d->map->matrix)
// 		free(d->map->matrix);
// 	if (d->map)
// 		free(d->map);
// 	if (d->cam)
// 		free(d->cam);
// 	if (d->mouse)
// 		free(d->mouse);
// 	if (d->title)
// 		free(d->title);
// 	if (d->mlx && d->img)
// 		mlx_destroy_image(d->mlx, d->img->img);
// 	if (d->mlx && d->win)
// 		mlx_destroy_window(d->mlx, d->win);
// 	if (d->img)
// 		free(d->img);
// 	if (d->mlx)
// 		free(d->mlx);
// 	if (d)
// 		free(d);
// 	if (!success)
// 		ft_error("MLX initialization failed.");
// 	else
// 		exit(EXIT_SUCCESS);
// 	return (0);
// }
