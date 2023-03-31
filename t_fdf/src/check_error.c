/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:32 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/31 16:00:41 by lilizarr         ###   ########.fr       */
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
		if (!ft_strlen(*argv))
			ft_error("-Invalid input");
		if (ft_atoi(*argv) > INT_MAX || ft_atoi(*argv) < INT_MIN)
			ft_error("iInvalid input");
		copy = *(argv);
		if (ft_strchr("+-", *copy))
			copy++;
		while (*copy && ft_isdigit(*copy))
			copy++;
		if (!ft_strchr("\n\0", *(copy)))
		{
			ft_printf("%d |",(char)*copy);
			ft_printf("%c \n",(char)*copy);
			ft_error("+Invalid map input");
		}
		argv++;
	}
}