/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 06:02:15 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_wall_x(t_dda *dda, t_player *player)
{
	if (dda->side == 0)
		dda->wall_x = player->y_player / BLOCK + dda->perp_wall_dist
			* dda->ray_dir_y;
	else
		dda->wall_x = player->x_player / BLOCK + dda->perp_wall_dist
			* dda->ray_dir_x;
	dda->wall_x -= floor(dda->wall_x);
}

static t_texture	*get_texture_north_south(t_dda *dda, t_game *game)
{
	if (dda->ray_dir_x > 0)
		return (&game->mappy.tex_so);
	else
		return (&game->mappy.tex_no);
}

static t_texture	*get_texture_east_west(t_dda *dda, t_game *game)
{
	if (dda->ray_dir_y > 0)
		return (&game->mappy.tex_ea);
	else
		return (&game->mappy.tex_we);
}

void	select_texture(t_dda *dda, t_wall *wall, t_game *game)
{
	calculate_wall_x(dda, &game->player);
	if (dda->side == 0)
		wall->texture = get_texture_north_south(dda, game);
	else
		wall->texture = get_texture_east_west(dda, game);
	wall->tex_x = (int)(dda->wall_x * (float)wall->texture->width);
	if ((dda->side == 0 && dda->ray_dir_x > 0)
		|| (dda->side == 1 && dda->ray_dir_y < 0))
		wall->tex_x = wall->texture->width - wall->tex_x - 1;
}
