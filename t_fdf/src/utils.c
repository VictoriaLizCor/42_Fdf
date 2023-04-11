/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/11 16:27:25 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include "../include/fdf.h"
#include <fdf.h>

void	ft_free(void **array)
{
	int	i;

	i = 0;
	while (*(array + i))
	{
		free(*(array + i));
		i++;
	}
	free(array);
}

// t_matrix	*last_element(t_matrix *ptr)
// {
// 	t_matrix	*last;

// 	last = ptr;
// 	while (last->next)
// 	{
// 		last = last->next;
// 	}
// 	return (last);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
void	check_map_data(t_map *map)
{
	int			row;
	int			col;
	int			tmp;
	t_matrix	*m;

	row = 0;
	m = *(map->matrix);
	ft_printf("%p\n", m);
	while (row < map->y_height)
	{
		col = 0;
		while (col < map->x_width)
		{
			tmp = row * map->x_width + col;
			ft_printf("(%d, %d, %d, %d) \t %p\n", m[tmp].y, m[tmp].x, \
			m[tmp].z, m[tmp].rgb, &m[tmp]);
			col++;
		}
		row++;
		ft_printf("\n");
	}
}
	// while(row < map->y_height * map->x_width)
	// {
	// 	ft_printf("(%d, %d, %d, %d) \t %p\n", m[row].y, m[row].x, \
	// 		m[row].z, m[row].rgb, &m[row]);
	// 	row++;
	// }

void	check_after_string_data(char *str, int ret, int extra)
{
	int		i;
	char	*buf;

	if (*str)
	{
		i = 0;
		buf = str;
		while (i < ret + extra)
		{
			if (!ft_strchr("\t\n\r\v\f", buf[i]))
				ft_printf("{ %c }",*(buf + i));
			else
				ft_printf("( %d )", *(buf + i));
			i++;
		}
		ft_printf("| %d\n", ret);
	}
	else
		ft_printf("\n ** null \n");
}
