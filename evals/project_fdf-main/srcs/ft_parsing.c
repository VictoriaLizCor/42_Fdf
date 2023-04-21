/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:57:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 13:56:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

/*
	Goal:	(1) To parse the data from argc, and argv
			(2) To set needed coefficients
	
	ft_mlx_create()			- Creates the instances of mlx like: windows, image
	ft_get_matrix()			- Get the matrix from the file
	ft_set_coefficients()	- Set the coefficients like angle, offset, and etc
	(?) ft_set_color()			- Set the colors
*/
void	ft_parsing(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_merror_clean_exit(data, "Wrong arguments", NULL);
	ft_mlx_create(data);
	ft_get_matrix(data, argv);
	ft_set_params(data);
}
