/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/06 16:32:08 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

//white = 16777215 = 0xffffff
int	hex_str2int_color(char *str_color)
{
	int	int_color;
	int	hex;
	int	len;
	int i;

	len = (int)ft_strlen(str_color) - 1;
	i = len;
	int_color = 0;
	while ( i > -1)
	{
		hex = str_color[i] - '0';
		if (!ft_isdigit(str_color[i]))
			hex = str_color[i] - 'A' + 10;
		int_color += hex * pow(16, (len - i));
		i--;
	}
	return (int_color);
}


// static void	add_node(t_matrix **matrix, t_matrix *new_node)
// {
// 	t_matrix	*last;

// 	if (!(*matrix))
// 		*matrix = new_node;
// 	else
// 	{
// 		last = last_element(*matrix);
// 		last->next = new_node;
// 		new_node->previous = last;
// 		// if (!(*(argv + 1)))
// 		// 	(*ptr)->previous = new_node;
// 	}
// }

void	read_map(t_map **map, int fd)
{
	char	*line;
	char	**line_data;
	int		tmp_x;

	*map = (t_map *)ft_calloc(sizeof(t_map), 1);
	while (1)
	{
		tmp_x = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		line_data = ft_split(line, ' ');
		(*map)->y_height++;
		get_map_size(line_data, &tmp_x);
		if (tmp_x != (*map)->x_width && (*map)->x_width)
			ft_error("Error: Invalid map size");
		(*map)->x_width = tmp_x;
		ft_free((void *)line_data);
		free(line);
	}
	if ((*map)->y_height < 1 || (*map)->x_width < 2)
		ft_error("Error: Empty map");
	if (close(fd) == -1)
			ft_error("Error: Unable to close file");
}

// (*m)->vectors[y * (*m)->width + x] = get_vector(x, y, split[x]);
void	fill_matrix(t_matrix **row, int width, int y, char **line_data)
{
	int			x;

	x = 0;
	ft_printf("map size: [ %d , %d ] \t\t %p\n", y, width, row);
	while (x < width)
	{
		printf("%d | %d \t", x, row[x]->z);
		(*row)[x].x = x + 1;
		// row[x]->y = y;
		// row[x]->z = ft_atoi(line_data[x]);
		// if (ft_strchr(line_data[x], ','))
		// 	row[x].color = hex_str2int_color(ft_strchr(line_data[x], ',') + 3);
		// else
		// 	row[x].color = (int)0xFFFFFF;
		printf("%d | %d \n", x, row[x]->z);
		x++;
	}
}

void	get_map_data(t_map **map, int fd)
{
	int			y;
	char		*line;
	char		**line_data;

	(*map)->matrix = (t_matrix **)(ft_calloc(sizeof(t_matrix *), \
						(*map)->y_height *(*map)->x_width));
	//delete matrix
	y = 0;
	while (y < (*map)->y_height)
	{
		line = get_next_line(fd);
		ft_printf("\n%s\n", line);
		line_data = ft_split(line, ' ');
		fill_matrix(&(*map)->matrix[y], (*map)->x_width, y + 1, line_data);
		ft_free((void *)line_data);
		free(line);
		y++;
	}
	if (close(fd) == -1)
			ft_error("Error: Unable to close file");
	// (*map)->matrix = matrix;
}

	// t_matrix	*new_node;

	// new_node = (t_matrix *)ft_calloc(sizeof(t_matrix), 1);
	// if (!new_node)
	// 	ft_error("Error: Unable to allocate map data");
		// new_node->x = x + 1;
		// new_node->y = (*map)->y_height;
		// new_node->z = ft_atoi(matrix[x]);
		// new_node->color = color;
		// add_node(&(*map)->matrix, new_node);
		
int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc != 2)
		ft_error("ERROR! |\t Valid input usage: \n ./fdf <filename>");
	else
	{
		ft_printf("%s\n", argv[1]);
		if (!ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
			ft_error("Error: Invalid file");
		read_map(&data.map, open(argv[1], O_RDONLY));
		get_map_data(&data.map, open(argv[1], O_RDONLY));
		ft_printf("size: [ %d , %d ]\n", data.map->y_height, data.map->x_width);
	}
	exit(EXIT_SUCCESS);
}

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