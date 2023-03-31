/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/31 16:21:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
// #include "../include/fdf.h"
// #include "fdf.h"

void	map_data(char **matrix, int *cols)
{
	while(*matrix)
	{
		(*cols)++;
		// ft_printf("%d | %s \n", *cols, *matrix);
		matrix++;
	}
}

void read_map(t_data *img, int fd)
{
	char	*line;
	char	**matrix;
	int		tmp_cols;

	while(1)
	{
		tmp_cols = 0;
		line = get_next_line(fd);
		if (!line)
			break;
		// ft_printf("%s\n", line);
		img->rows++;
		matrix = ft_split(line, ' ');
		check_integers(matrix);
		ft_printf("%d \n",img->rows);
		map_data(matrix, &tmp_cols);
		// if (tmp_cols != img->cols)
		// 	ft_error("Invalid map");
		img->cols = tmp_cols;

	}
	ft_printf("\n%d | %d\n", img->rows, img->cols);
	if (!img->cols || !img->rows)
		ft_error("*Invalid input");
	free(line);
	ft_strfree(matrix);
}

int	main(int argc, char **argv)
{
	void			*mlx;
	void			*mlx_win;
	static t_data	img;
	int				fd;

	if (argc != 2)
	{
		ft_error("ERROR! |\t Valid input usage: \n ./fdf <filename>");
	}
	else
	{
		ft_printf("%s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		read_map(&img, fd);
		if (close(fd) == -1)
		{
			ft_error("| Error closing file |");
			return (1);
		}
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HIGHT, "42 FDF");
		// // mlx_new_image(mlx_ptr_t *mlx_ptr, int width, int height)
		// img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HIGHT);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		// 							&img.endian);
		// my_mlx_pixel_put(&img, 100, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 101, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 102, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 103, 100, 0x00FFFFF);
		// mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
		// mlx_loop(mlx);
		// mlx_destroy_image(mlx, img.img);
		// mlx_destroy_window(mlx, mlx_win);
	}
	return (0);
}
