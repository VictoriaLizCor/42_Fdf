/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/11 17:55:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void	render()
// {
	
// }

// int	init_render(t_data **data, char *file)
// {
// 	(*data)->title = ft_strjoin("42 Fdf | ", file);
// 	(*data)->mlx = mlx_init();
// 	if (!(*data)->mlx)
// 		return (-1);
// 	(*data)->win = mlx_new_window((*data)->mlx, WIN_WIDTH, WIN_HIGHT, \
// 								(*data)->title);
// 	if (!(*data)->win)
// 		return (-1);
// 	return (0);
// }
// ft_printf("%p\n", (*data)->win);

int	init_render(t_data **data, char *file)
{
	ft_printf("map: \t\t%p\n", (*data)->map);
	ft_printf("matrix: \t%p\n", *(*data)->map->matrix);
	// check_map_data((*data)->map);
	(*data)->title = ft_strjoin("42 Fdf | ", file);
	(*data)->mlx = mlx_init();
	if (!((*data)->mlx))
		return (-1);
	printf("mlx : \t\t%p\n", (*data)->mlx);
	(*data)->win = mlx_new_window((*data)->mlx, WIN_WIDTH, WIN_HIGHT, \
								(*data)->title);
	if (!((*data)->win))
		return (-1);
	printf("window: \t%p\n", (*data)->win);
	// check_map_data((*data)->map);
	return (0);
}