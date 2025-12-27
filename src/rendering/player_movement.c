/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:01:16 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:09:56 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_backward(t_player *player, float cos_a, float sin_a,
		t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = player->x_player - (cos_a * player->speed);
	new_y = player->y_player - (sin_a * player->speed);
	if (!check_collision(new_x, new_y, game))
	{
		player->x_player = new_x;
		player->y_player = new_y;
	}
}

static void	move_left(t_player *player, float cos_a, float sin_a, t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = player->x_player + (sin_a * player->speed);
	new_y = player->y_player - (cos_a * player->speed);
	if (!check_collision(new_x, new_y, game))
	{
		player->x_player = new_x;
		player->y_player = new_y;
	}
}

static void	move_right(t_player *player, float cos_a, float sin_a, t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = player->x_player - (sin_a * player->speed);
	new_y = player->y_player + (cos_a * player->speed);
	if (!check_collision(new_x, new_y, game))
	{
		player->x_player = new_x;
		player->y_player = new_y;
	}
}

void	apply_movement(t_player *player, float cos_a, float sin_a, t_game *game)
{
	if (player->player_down)
		move_backward(player, cos_a, sin_a, game);
	if (player->player_left)
		move_left(player, cos_a, sin_a, game);
	if (player->player_right)
		move_right(player, cos_a, sin_a, game);
}
