/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_update_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:09:03 by jaeskim           #+#    #+#             */
/*   Updated: 2021/03/03 03:07:05 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UPDATE_BONUS_H
# define CUB3D_UPDATE_BONUS_H

# include "cub3d_bonus.h"

void	update(t_cub3d *g);
void	update_mouse(t_cub3d *g);
void	update_player(t_cub3d *g);
void	update_all_rays(t_cub3d *g);
void	update_sprite(t_cub3d *g);
void	update_item(t_cub3d *g);
void	update_count(t_cub3d *g);

#endif
