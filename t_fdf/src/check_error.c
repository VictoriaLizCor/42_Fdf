/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:32 by lilizarr          #+#    #+#             */
/*   Updated: 2023/04/03 17:51:21 by lilizarr         ###   ########.fr       */
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

void	check_integers(char **argv)
{
	char	*copy;

	while (*argv)
	{
		if (ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
			ft_error("Invalid value input");
		copy = *argv;
		if (ft_strchr("+-", *copy))
			copy++;
		while (ft_isdigit(*copy))
		{
			copy++;
		}
		if (!ft_strchr("0x\n\0", *(copy)) && !)
		{
			ft_error("+Invalid map input");
		}
		argv++;
	}
}

void	map_data(char **matrix, int *cols)
{
	while (*matrix)
	{
		(*cols)++;
		ft_printf("%d | %s \n", *cols, *matrix);
		matrix++;
	}
}
