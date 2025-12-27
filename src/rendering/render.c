/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:04 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	render_debug_mode(t_game *game)
{
	t_square	sq;

	sq.x = game->player.x_player;
	sq.y = game->player.y_player;
	sq.size = 10;
	sq.color = 0x00FF00;
	draw_square(sq, game);
	draw_map(game);
}

static void	cast_all_rays(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray_dda(game, x);
		x++;
	}
}

int	draw_loop(t_game *game)
{
	move_player(game);
	draw_floor_ceiling(game);
	if (DEBUG)
		render_debug_mode(game);
	cast_all_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

static void	apply_rotation(t_player *player)
{
	if (player->left_player_rot)
		player->angle -= player->angle_speed;
	if (player->right_player_rot)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	move_player(t_game *game)
{
	float	cos_angle;
	float	sin_angle;
	float	new_x;
	float	new_y;

	apply_rotation(&game->player);
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	if (game->player.player_up)
	{
		new_x = game->player.x_player + (cos_angle * game->player.speed);
		new_y = game->player.y_player + (sin_angle * game->player.speed);
		if (!check_collision(new_x, new_y, game))
		{
			game->player.x_player = new_x;
			game->player.y_player = new_y;
		}
	}
	apply_movement(&game->player, cos_angle, sin_angle, game);
}
