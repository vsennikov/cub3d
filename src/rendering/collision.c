/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:59:16 by chmarque          #+#    #+#             */
/*   Updated: 2026/02/11 15:56:43 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_out_of_bounds(float px, float py, t_game *game)
{
	int	x;
	int	y;

	if (px < 0 || py < 0)
		return (true);
	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (x >= game->mappy.width || y >= game->mappy.height)
		return (true);
	return (false);
}

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	if (is_out_of_bounds(px, py, game))
		return (true);
	if (!game->mappy.map)
		return (true);
	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (!game->mappy.map[y])
		return (true);
	if (!game->mappy.map[y][x])
		return (true);
	if (game->mappy.map[y][x] == '1')
		return (true);
	return (false);
}

bool	check_collision(float px, float py, t_game *game)
{
	float	margin;

	margin = 16.0;
	if (touch(px + margin, py + margin, game))
		return (true);
	if (touch(px - margin, py + margin, game))
		return (true);
	if (touch(px + margin, py - margin, game))
		return (true);
	if (touch(px - margin, py - margin, game))
		return (true);
	return (false);
}

bool	is_wall(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->mappy.width || y < 0 || y >= game->mappy.height)
		return (true);
	if (!game->mappy.map || !game->mappy.map[y])
		return (true);
	if (game->mappy.map[y][x] == '1')
		return (true);
	return (false);
}
