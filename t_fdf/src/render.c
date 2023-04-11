/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/11 16:52:35 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void	render()
// {
	
// }

int	init_render(t_data **data, char *file)
{
	printf("map %p\n", (*data)->map);
	printf("matrix %p\n", &(*data)->map->matrix);
	check_map_data((*data)->map);
	printf("%p\n", (*data)->mlx);
	(*data)->title = ft_strjoin("42 Fdf | ", file);
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		return (-1);
	(*data)->win = mlx_new_window((*data)->mlx, WIN_WIDTH, WIN_HIGHT, \
								(*data)->title);
	if (!(*data)->win)
		return (-1);
	check_map_data((*data)->map);
	return (0);
}
// ft_printf("%p\n", (*data)->win);