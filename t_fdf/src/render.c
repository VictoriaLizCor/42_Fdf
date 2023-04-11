/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:54:38 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/11 13:51:02 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

// void	render()
// {
	
// }

int	init_render(t_data *data, void *mlx, char *file)
{
	data->mlx = mlx;
	if (!data->mlx)
		return (-1);
	data->title = ft_strjoin("42 Fdf | ", file);
	ft_printf("title: %s | %p\n", data->title, data->title);
	//free(data->title);
	ft_printf("%p\n", *(data->map->matrix));
	free(*(data->map->matrix));
	return (0);
	// free((*(data->map->matrix)));
}
