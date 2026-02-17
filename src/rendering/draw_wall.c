/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:59:56 by chmarque          #+#    #+#             */
/*   Updated: 2026/02/17 08:19:41 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall_slice(t_wall *wall, int x, t_game *game)
{
	int				y;
	int				tex_y;
	float			step;
	float			tex_pos;
	unsigned int	color;

	step = (float)wall->texture->height / (float)wall->height;
	tex_pos = (wall->start_y - HEIGHT / 2 + wall->height / 2) * step;
	y = wall->start_y;
	while (y < wall->end_y)
	{
		tex_y = (int)tex_pos % wall->texture->height;
		tex_pos += step;
		color = get_texture_pixel(wall->texture, wall->tex_x, tex_y);
		put_pixel(x, y, color, game);
		y++;
	}
}
