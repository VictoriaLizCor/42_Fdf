/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:26:06 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/03 03:07:04 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update(t_cub3d *g)
{
	update_mouse(g);
	update_player(g);
	update_item(g);
	g->dir_plane.x = g->dir.x - g->plane.x;
	g->dir_plane.y = g->dir.y - g->plane.y;
	update_all_rays(g);
	update_sprite(g);
	update_count(g);
}
