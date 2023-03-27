/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/27 14:08:51 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../xml/minilibx_macos/mlx.h"
#include "../lib/libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

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
	exit(0);
}
