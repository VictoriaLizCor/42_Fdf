/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/28 12:12:24 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		row[x].z = (double)(ft_atol(row_data[x]));
		if (row[x].z < (*m)->z_min)
			(*m)->z_min = row[x].z;
		if (row[x].z > (*m)->z_max)
			(*m)->z_max = row[x].z;
		row[x].rgb.rgb = (int)0xFFFFFF;
		if (ft_strchr(row_data[x], ','))
		{
			int_rgb(&row[x].rgb, ft_strchr(row_data[x], ',') + 3);
			(*m)->color_change = 1;
		}
		x++;
	}
	(*m)->max_val = find_max((double)(*m)->x_max, \
	(double)(*m)->y_max, (*m)->z_max);
}

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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (argc != 2)
		ft_error("Invalid command\nValid input usage: \n ./fdf <filename.fdf>");
	if (!(ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))))
		ft_error(" Invalid file");
	if ((read_map(&data->map, open(argv[1], O_RDONLY)) == -1) || \
		(get_map_data(&data->map, open(argv[1], O_RDONLY), 0) == -1))
		ft_error(strerror(errno));
	if (init_render_data(&data, argv[1]) == -1)
		clean_data(data, 0);
	render(data, 0, 0);
	mlx_key_hook(data->win, key_pressed, data);
	mlx_hook(data->win, 17, 0, clean_data, data);
	mlx_loop(data->mlx);
	return (0);
}
