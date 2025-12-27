/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:00:34 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:09:39 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_free_mlx_allocation(game);
	else if (keysym == XK_w)
		game->player.player_up = true;
	else if (keysym == XK_s)
		game->player.player_down = true;
	else if (keysym == XK_a)
		game->player.player_left = true;
	else if (keysym == XK_d)
		game->player.player_right = true;
	else if (keysym == XK_Right)
		game->player.right_player_rot = true;
	else if (keysym == XK_Left)
		game->player.left_player_rot = true;
	return (0);
}

int	key_release(int keysym, t_game *game)
{
	if (keysym == XK_w)
		game->player.player_up = false;
	else if (keysym == XK_s)
		game->player.player_down = false;
	else if (keysym == XK_a)
		game->player.player_left = false;
	else if (keysym == XK_d)
		game->player.player_right = false;
	else if (keysym == XK_Right)
		game->player.right_player_rot = false;
	else if (keysym == XK_Left)
		game->player.left_player_rot = false;
	return (0);
}
