/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:01:25 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 06:01:27 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_step_and_side_dist(t_dda *dda, t_player *player)
{
	float	pos_x;
	float	pos_y;

	pos_x = player->x_player / BLOCK;
	pos_y = player->y_player / BLOCK;
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - pos_x) * dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - pos_y) * dda->delta_dist_y;
	}
}

void	init_dda(t_dda *dda, t_player *player, float angle)
{
	dda->ray_dir_x = cos(angle);
	dda->ray_dir_y = sin(angle);
	dda->map_x = (int)(player->x_player / BLOCK);
	dda->map_y = (int)(player->y_player / BLOCK);
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	calculate_step_and_side_dist(dda, player);
}

static bool	is_wall(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->mappy.width || y < 0 || y >= game->mappy.height)
		return (true);
	if (!game->mappy.map || !game->mappy.map[y])
		return (true);
	if (game->mappy.map[y][x] == '1')
		return (true);
	return (false);
}

void	perform_dda(t_dda *dda, t_game *game)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (is_wall(dda->map_x, dda->map_y, game))
			hit = true;
	}
}

void	calculate_wall_dda(t_dda *dda, t_wall *wall, float angle_diff)
{
	float	dist_pixels;
	float	corrected_dist;

	if (dda->side == 0)
		dda->perp_wall_dist = (dda->side_dist_x - dda->delta_dist_x);
	else
		dda->perp_wall_dist = (dda->side_dist_y - dda->delta_dist_y);
	dist_pixels = dda->perp_wall_dist * BLOCK;
	corrected_dist = dist_pixels * cos(angle_diff);
	wall->height = (BLOCK / corrected_dist) * (WIDTH / 2);
	wall->start_y = (HEIGHT - wall->height) / 2;
	wall->end_y = wall->start_y + wall->height;
}

void	cast_ray_dda(t_game *game, int x)
{
	t_dda	dda;
	t_wall	wall;
	float	angle;
	float	angle_diff;

	angle = game->player.angle - (game->player.fov / 2);
	angle += (game->player.fov / WIDTH) * x;
	angle_diff = angle - game->player.angle;
	init_dda(&dda, &game->player, angle);
	perform_dda(&dda, game);
	calculate_wall_dda(&dda, &wall, angle_diff);
	select_texture(&dda, &wall, game);
	draw_wall_slice(&wall, x, game);
}
