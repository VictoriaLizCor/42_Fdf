/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:47:17 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:18:18 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	glb;

	if (ac == 1)
	{
		print_usage(1);
	}
	else
	{
		if (fdf(&glb, av[1]) == 0)
		{
			print_error(3, 0);
		}
	}
	return (0);
}