/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:59:16 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 05:59:20 by chmarque         ###   ########.fr       */
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

	margin = 2.0;
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
