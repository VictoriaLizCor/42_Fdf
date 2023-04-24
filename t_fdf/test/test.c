/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/24 21:24:18 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#ifdef __APPLE__
# include "mlx.h"
#else
# include "mlx.h"
# include "mlx_int.h"
#endif


void	my_mlx_pixel_put(t_im *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + \
	x * (img->bpp / 8));
	*(unsigned int *)(dst) = color;
}

void	main(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!(data->mlx = mlx_init()))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, 1080, 720, "Hello world!");
	data->img = (t_im *)ft_calloc(sizeof(t_im), 1);
	data->img->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
	&data->img->line_length, &data->img->endian);
	my_mlx_pixel_put(data->img, 100, 100, 0x00FFFFF);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 150, 150);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

// cc -I include/ -I /usr/include/ -I lib/libft/ -I lib/minilibx_linux src/test.c -L lib/minilibx_linux/ -lmlx -lXext -lX11 -lm -lbsd -L lib/libft/ -lft