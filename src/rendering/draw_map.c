/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:59:46 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:09:22 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_map(t_game *game)
{
	int			x;
	int			y;
	t_square	sq;

	y = 0;
	sq.size = BLOCK;
	sq.color = 0x0000FF;
	while (game->mappy.map[y])
	{
		x = 0;
		while (game->mappy.map[y][x] != '\0')
		{
			if (game->mappy.map[y][x] == '1')
			{
				sq.x = x * BLOCK;
				sq.y = y * BLOCK;
				draw_square(sq, game);
			}
			x++;
		}
		y++;
	}
}
