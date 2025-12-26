/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:00:26 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 06:00:28 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	init_player_direction(char orientation)
{
	if (orientation == 'N')
		return (3 * PI / 2);
	else if (orientation == 'S')
		return (PI / 2);
	else if (orientation == 'E')
		return (0);
	else if (orientation == 'W')
		return (PI);
	return (PI / 2);
}

static void	init_player_movement(t_player *player)
{
	player->player_down = false;
	player->player_left = false;
	player->player_right = false;
	player->player_up = false;
	player->left_player_rot = false;
	player->right_player_rot = false;
}

void	ft_init_player(t_player *player)
{
	player->x_player = WIDTH / 2;
	player->y_player = HEIGHT / 2;
	player->angle = init_player_direction('S');
	player->speed = 3;
	player->angle_speed = 0.03;
	player->fov = PI / 3;
	init_player_movement(player);
}
