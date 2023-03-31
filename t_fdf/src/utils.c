/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/31 16:19:09 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
// #include "../include/fdf.h"
#include <fdf.h>

void	ft_strfree(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	free(split);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	check_after_string_data(char *str, int ret, int extra)
{
	int		i;
	char	*buf;

	if ((*str))
	{
		i = 0;
		buf = str;
		ft_printf("\n -- [%p] %zu\n", buf, ft_strlen(buf));
		while (i < ret + extra)
		{
			if (!ft_strchr("\t\n\r\v\f", buf[i]))
				ft_printf("%d_[ %p ]{ %c }", i, (buf + i), *(buf + i));
			else
				ft_printf("%d_[ %p ]( %d )", i, (buf + i), *(buf + i));
			if (i % 2 == 0)
				ft_printf("\t\t");
			else
				ft_printf("\n");
			i++;
		}
	}
	else
		ft_printf("\n ** null \n");
}