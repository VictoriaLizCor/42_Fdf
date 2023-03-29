/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/29 16:28:48 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "../include/fdf.h"
// #include "fdf.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (ac == 1)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1080, 720, "Hello world!");
		img.img = mlx_new_image(mlx, 1080, 720);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		my_mlx_pixel_put(&img, 100, 100, 0x00FFFFF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
		mlx_loop(mlx);
		mlx_destroy_image(mlx, img.img);
		mlx_destroy_window(mlx, mlx_win);
	}
	return (0);
}
