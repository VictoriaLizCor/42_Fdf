/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:26:11 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/03 06:29:53 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		render(t_cub3d *g)
{
	render_ceiling(g);
	render_floor(g);
	render_wall(g);
	render_sprite(g);
	if (g->key.m)
	{
		render_map(g);
		render_lifebar(g);
	}
}
