/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:56:50 by pfragnou          #+#    #+#             */
/*   Updated: 2023/04/17 13:33:21 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include mlx.h>

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int		fdf_exit(t_fdf *fdf)
{
	free_map(&fdf->map);
	if (fdf->mlx.mlx && fdf->mlx.window)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.window);
	if (fdf->mlx.mlx && fdf->mlx.image)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.image);
	exit(fdf->flag.exit_value);
}
