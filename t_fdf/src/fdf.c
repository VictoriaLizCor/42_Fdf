/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/29 17:47:46 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "../include/fdf.h"
// #include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2)
	{
		ft_error("Error! Valid input usage: ./fdf <filename>");
	}
	else
	{
		ft_printf("%s\n", *argv);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HIGHT, "Hello world!");
		img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HIGHT);
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
