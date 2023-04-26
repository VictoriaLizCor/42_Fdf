/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/26 12:56:45 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//white = 16777215 = 0xffffff

static int	read_map(t_map **map, int fd)
{
	char	*row;
	char	**row_data;
	int		tmp_x;

	if (fd < 0)
		return (-1);
	*map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!*map)
		ft_error("Unable to allocate map");
	while (1)
	{
		tmp_x = 0;
		row = get_next_line(fd);
		if (!row)
			break ;
		row_data = ft_split(row, ' ');
		(*map)->y_max++;
		get_map_size(row_data, &tmp_x);
		if (tmp_x != (*map)->x_max && (*map)->x_max)
			ft_error("Invalid map size");
		(*map)->x_max = tmp_x;
		ft_free((void *)row_data);
		free(row);
	}
	return (close(fd));
}

static void	fill_matrix(t_matrix *row, t_map **m, int y, char **row_data)
{
	int	x;

	x = 0;
	while (x < (*m)->x_max)
	{
		row[x].x = x + 1;
		row[x].y = y;
		row[x].z = (float)ft_atoi(row_data[x]);
		if (row[x].z < (*m)->z_min)
			(*m)->z_min = (int)row[x].z;
		if (row[x].z > (*m)->z_max)
			(*m)->z_max = (int)row[x].z;
		row[x].rgb.rgb = (int)0xFFFFFF;
		if (ft_strchr(row_data[x], ','))
		{
			int_rgb(&row[x].rgb, ft_strchr(row_data[x], ',') + 3);
			(*m)->color_change = 1;
		}
		x++;
	}
	(*m)->max_val = find_max((float)(*m)->x_max, \
	(float)(*m)->y_max, (float)(*m)->z_max);
}
	// ft_printf("map size: [ %d , %d ] \t\t %p\n", y, (*map)->x_max, row);
		// ft_printf("%d | %d \t", x, row[x].z);
	// printf("%d | %d \n", x, row[x].z);

static int	get_map_data(t_map **map, int fd, int y)
{
	char		*row;
	char		**row_data;

	if (fd < 0 || !*map)
		return (-1);
	if ((*map)->y_max < 1 || (*map)->x_max < 2)
		ft_error("Empty map");
	(*map)->matrix = (t_matrix *)ft_calloc(sizeof(t_matrix), \
				(*map)->y_max * (*map)->x_max);
	if (!(*map)->matrix)
		ft_error("Unable to allocate data matrix");
	(*map)->z_min = INT_MAX;
	(*map)->z_max = INT_MIN;
	while (y < (*map)->y_max)
	{
		row = get_next_line(fd);
		row_data = ft_split(row, ' ');
		fill_matrix(&(*map)->matrix[y * (*map)->x_max], \
					&*map, y + 1, row_data);
		ft_free((void *)row_data);
		free(row);
		y++;
	}
	return (close(fd));
}
	// ft_printf("matrix_original : %p\n", matrix);
	// ft_printf("matrix_creation : %p\n", *(*map)->matrix);

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	printf("data: \t%p\n", &data);
	if (argc != 2)
		ft_error("Invalid command\nValid input usage: \n ./fdf <filename.fdf>");
	if (!(ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))))
		ft_error(" Invalid file");
	if ((read_map(&data->map, open(argv[1], O_RDONLY)) == -1) || \
		(get_map_data(&data->map, open(argv[1], O_RDONLY), 0) == -1))
		ft_error(strerror(errno));
	if (init_render_data(&data, argv[1]) == -1)
		free_data(data, 0);
	render(data, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 17, 0, free_data, data);
	mlx_loop(data->mlx);
	exit(EXIT_SUCCESS);
}

// exit (EXIT_SUCCESS);
// 	ft_printf("read_matrix : %p\n", data->map->matrix);
// 	ft_printf("\n\nsize:[ %d, %d ]\n\n", data->map->y_max,
// 											data->map->x_max)
	// free(*(data->map->matrix)); // free((void *)(*(data.map->matrix)));
	// free(data->map);
	// free(data->title);
	// free((void *)(*(data.map->matrix)));
	// free((*(data.map->matrix)));
		// printf("\n%p | %p\n\n", data.map, (void *)(*(data.map->matrix)));
		// free((*(data.map->matrix)));
	// while (i < 100)
	// 	ft_printf("%d, %s\n",i,  strerror(i++));
	// 
		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HIGHT, "42 FDF");
		// // mlx_new_image(mlx_ptr_t *mlx_ptr, int width, int height)
		// img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HIGHT);
		// img.addr = mlx_get_data_addr(img.img, &img.its_per_pixel,
		// addindex&img.line_length,
		// 							&img.endian);
		// my_mlx_pixel_put(&img, 100, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 101, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 102, 100, 0x00FFFFF);
		// my_mlx_pixel_put(&img, 103, 100, 0x00FFFFF);
		// mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
		// mlx_loop(mlx);
		// mlx_destroy_image(mlx, img.img);
		// mlx_destroy_window(mlx, mlx_win);