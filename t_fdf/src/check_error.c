/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:32 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/14 14:12:08 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
#include <fdf.h>
// #include "../include/fdf.h"

void	ft_error(char *msg)
{
	ft_printf("Error : %s \n", msg);
	exit(EXIT_FAILURE);
}

static void	check_color(char *str)
{
	size_t	len;

	len = 8;
	if (ft_strchr(str, '\n'))
		len = 9;
	if (ft_strnstr(str, "0x", 2) && ft_strlen(str) <= len)
	{
		str = str + 2;
		while (*str != '\n' && *str != '\0')
		{
			*str = ft_toupper(*str);
			if ((*str < '0' || *str > '9') && (*str < 'A' || *str > 'F'))
				ft_error("+Invalid color input");
			str++;
		}
	}
	else
		ft_error("*Invalid color input");
}

void	get_map_size(char **matrix, int *cols)
{
	int		len;
	char	*copy;

	while (*matrix)
	{
		if (ft_strlen(*matrix) == 1 && !ft_isdigit(*(*matrix)))
			ft_error("_Invalid map value input");
		len = ft_strlen(*matrix);
		if (ft_strchr(*matrix, ','))
			len = len - ft_strlen(ft_strchr(*matrix, ','));
		copy = *matrix;
		if (ft_strchr("+-", *copy))
			copy++;
		while (ft_isdigit(*copy))
			copy++;
		if (ft_strchr(copy, ','))
		{
			check_color(copy + 1);
			copy = copy + ft_strlen(ft_strchr(copy, ','));
		}
		if (!ft_strchr("\n", *(copy)) && (int)ft_strlen(copy) <= len)
			ft_error("+Invalid map value input");
		(*cols)++;
		matrix++;
	}
}

// check_after_string_data(*matrix, ft_strlen(*matrix), 0);
// ft_printf("%c\n", *(*matrix));
// if (ft_atoi(*matrix) > INT_MAX || ft_atoi(*matrix) < INT_MIN)
// 	ft_error("Invalid value input");