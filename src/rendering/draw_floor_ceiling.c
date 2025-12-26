/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:59:37 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 05:59:41 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->mappy.color_ceiling, game);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->mappy.color_floor, game);
			x++;
		}
		y++;
	}
}

void	draw_floor_ceiling(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
