/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:10:06 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/03 03:36:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_BONUS_H
# define CUB3D_RENDER_BONUS_H

# include "cub3d_bonus.h"

void	render(t_cub3d *g);
void	render_floor(t_cub3d *g);
void	render_ceiling(t_cub3d *g);
void	render_wall(t_cub3d *g);
void	render_sprite(t_cub3d *g);
void	render_map(t_cub3d *g);
void	render_lifebar(t_cub3d *g);
void	render_gameover(t_cub3d *g);
void	render_finish(t_cub3d *g);

#endif
