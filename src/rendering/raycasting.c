/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:01 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_ray(t_ray *ray, t_player *player, float angle)
{
	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);
	ray->pos_x = player->x_player;
	ray->pos_y = player->y_player;
	ray->distance = 0;
}

static void	cast_single_ray(t_ray *ray, t_game *game)
{
	while (!touch(ray->pos_x, ray->pos_y, game))
	{
		if (DEBUG)
			put_pixel(ray->pos_x, ray->pos_y, 0xFF0000, game);
		ray->pos_x += ray->dir_x;
		ray->pos_y += ray->dir_y;
	}
}

void	calculate_wall(t_ray *ray, t_wall *wall, t_game *game)
{
	float	angle_diff;
	float	corrected_dist;

	angle_diff = atan2(ray->dir_y, ray->dir_x) - game->player.angle;
	ray->distance = calculate_distance(ray->pos_x - game->player.x_player,
			ray->pos_y - game->player.y_player);
	corrected_dist = ray->distance * cos(angle_diff);
	wall->height = (BLOCK / corrected_dist) * (WIDTH / 2);
	wall->start_y = (HEIGHT - wall->height) / 2;
	wall->end_y = wall->start_y + wall->height;
	wall->color = 0xFFFFFF;
}

void	cast_ray(t_game *game, int x)
{
	t_ray	local_ray;
	t_wall	wall;
	float	angle;

	angle = game->player.angle - (game->player.fov / 2);
	angle += (game->player.fov / WIDTH) * x;
	init_ray(&local_ray, &game->player, angle);
	cast_single_ray(&local_ray, game);
	if (!DEBUG)
	{
		calculate_wall(&local_ray, &wall, game);
		draw_wall_slice(&wall, x, game);
	}
}
