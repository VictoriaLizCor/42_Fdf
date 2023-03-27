/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:38:28 by jaeskim           #+#    #+#             */
/*   Updated: 2021/02/16 17:25:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_ceiling(t_cub3d *g)
{
	g_color = g->bg_color[C - F];
	rect(&g->v, new_vec(0, 0), g->v.width, g->v.height / 2);
}
