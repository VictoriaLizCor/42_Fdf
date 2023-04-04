/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:32 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/04 17:21:39 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"
#include <fdf.h>
// #include "../include/fdf.h"

void	ft_error(char *msg)
{
	ft_printf("\n %s \n\n", msg);
	exit(EXIT_FAILURE);
}

void	check_values()
{
	
}

void	get_data_size(char **matrix, int *cols)
{
	char	*copy;
	int		len;

	while (*matrix)
	{
		if (ft_strlen(*matrix) == 1 && !ft_isdigit(*(*matrix)))
			ft_error("_Invalid map input");
		check_after_string_data(*matrix, ft_strlen(*matrix), 0);
		len = ft_strlen(*matrix);
		if (ft_strchr(*matrix, ','))
			len = len - ft_strlen(ft_strchr(*matrix, ','));
		copy = *matrix;
		if (ft_strchr("+-", *copy))
			copy++;
		while (ft_isdigit(*copy))
			copy++;
		if (ft_strchr(copy, ','))
			copy = copy + ft_strlen(ft_strchr(copy, ','));
		if (!ft_strchr("\n", *(copy)) && (int)ft_strlen(copy) <= len)
			ft_error("+Invalid map input");
		(*cols)++;
		matrix++;
	}
}

// ft_printf("%c\n", *(*matrix));
// if (ft_atoi(*matrix) > INT_MAX || ft_atoi(*matrix) < INT_MIN)
// 	ft_error("Invalid value input");