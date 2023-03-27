/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:32:35 by jaeskim           #+#    #+#             */
/*   Updated: 2021/02/15 22:04:30 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTIL_H
# define CUB3D_UTIL_H

# include "cub3d.h"

extern t_color	g_color;

t_vec	new_vec(float x, float y);
t_ivec	new_ivec(int x, int y);
t_vec	rot_vec(t_vec v, float angle);

void	normalise_pos(t_cub3d *g, t_vec *pos);
void	normalise_ipos(t_cub3d *g, t_ivec *pos);

t_color	rgba(t_uc r, t_uc g, t_uc b, float a);
void	color_rgba(t_uc r, t_uc g, t_uc b, float a);

t_color	calc_rgba(t_color background, t_color color);
void	put_pixel(t_img *view, int x, int y);

void	line(t_img *view, t_vec a, t_vec b);
void	rect(t_img *view, t_vec position, int width, int height);
void	mid_point_rect(t_img *view, t_vec position, int width, int height);

#endif
