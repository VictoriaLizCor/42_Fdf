/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:43:32 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/29 21:10:00 by lilizarr         ###   ########.fr       */
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
