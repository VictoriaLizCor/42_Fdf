/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:33 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/27 17:29:22 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # ifdef __APPLE__
// #  include "lib/minilibx_macos/mlx.h"
// # else
// #  include "../lib/minilibx_linux/mlx.h"
// # endif

// #include "lib/libft/libft.h"
#include "libft.h"
#include <mlx.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif