/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/05 17:20:53 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>



static void	fill_data(t_matrix **ptr, int z)
{
	t_matrix	*new_node;
	t_matrix	*last;

	new_node = (t_matrix *)ft_calloc(sizeof(t_matrix), 1);
	if (!new_node)
		ft_error("Error: Unable to allocate map data");
	new_node->z = z;
	if (!(*ptr))
		*ptr = new_node;
	else
	{
		last = last_element(*ptr);
		last->next = new_node;
		new_node->previous = last;
		// if (!(*(argv + 1)))
		// 	(*ptr)->previous = new_node;
	}
}

//white = 16777215 = 0xffffff
int	define_hex2int_color(char *str_color)
{
	int	int_color;
	int	hex;
	int	i;

	i = 0;
	int_color = 0;
	while (str_color[i])
	{
		hex = str_color[i] - '0';
		if (!ft_isdigit(str_color[i]))
			hex = str_color[i] - 'A' + 10;
		int_color += hex * pow(16, i);
		i++;
	}
	return (int_color);
}

void	get_map_data(t_map **map, char **matrix)
{
	int	cols;
	int	color;

	color = (int)0xFF00;
	cols = 0;
	ft_printf("map size: [ %d , %d ]\n", (*map)->y_height, (*map)->x_width);
	while (cols < (*map)->x_width)
	{
		// ft_printf("%d | %s\n", cols + 1, matrix[cols]);
		if (ft_strchr(matrix[cols], ','))
		{
			printf("*%d | %d | \n", color, define_hex2int_color("FF00"));
			color = define_hex2int_color(ft_strchr(matrix[cols], ',') + 1);
			printf("%s | %d | %d\n", ft_strchr(matrix[cols], ',') + 1, color, (int)0xFFAA00);
		}
		fill_data(&(*map)->matrix, ft_atoi(matrix[cols]));
		cols++;
	}
}

void	read_map(t_map **map, int fd)
{
	char	*line;
	char	**matrix;
	int		tmp_cols;

	*map = (t_map *)ft_calloc(sizeof(t_map), 1);
	while (1)
	{
		tmp_cols = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix = ft_split(line, ' ');
		(*map)->y_height++;
		get_map_size(matrix, &tmp_cols);
		if (tmp_cols != (*map)->x_width && (*map)->x_width)
			ft_error("Error: Invalid map size");
		(*map)->x_width = tmp_cols;
		get_map_data(&*map, matrix);
		ft_free((void *)matrix);
		free(line);
	}
	if ((*map)->y_height < 1 || (*map)->x_width < 2)
		ft_error("Error: Empty map");
}

int	main(int argc, char **argv)
{
	static t_data	data;
	int				fd;

	if (argc != 2)
		ft_error("ERROR! |\t Valid input usage: \n ./fdf <filename>");
	else
	{
		ft_printf("%s\n", argv[1]);
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			ft_error("Error: Invalid file");
		fd = open(argv[1], O_RDONLY);
		read_map(&data.map, fd);
		ft_printf("size: [ %d , %d ]\n", data.map->y_height, data.map->x_width);
		if (close(fd) == -1)
			ft_error("Error: Unable to close file");
	}
	exit(EXIT_SUCCESS);
}

		// mlx = mlx_init();
		// mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HIGHT, "42 FDF");
		// // mlx_new_image(mlx_ptr_t *mlx_ptr, int width, int height)
		// img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HIGHT);
		// img.addr = mlx_get_data_addr(img.img, &img.its_per_pixel, \ 
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