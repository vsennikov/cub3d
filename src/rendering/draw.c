/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:00:04 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:09:28 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_square_horizontal(t_square sq, t_game *g)
{
	int	i;

	i = 0;
	while (i < sq.size)
	{
		put_pixel(sq.x + i, sq.y, sq.color, g);
		i++;
	}
	i = 0;
	while (i < sq.size)
	{
		put_pixel(sq.x + i, sq.y + sq.size, sq.color, g);
		i++;
	}
}

static void	draw_square_vertical(t_square sq, t_game *g)
{
	int	i;

	i = 0;
	while (i < sq.size)
	{
		put_pixel(sq.x, sq.y + i, sq.color, g);
		i++;
	}
	i = 0;
	while (i < sq.size)
	{
		put_pixel(sq.x + sq.size, sq.y + i, sq.color, g);
		i++;
	}
}

void	draw_square(t_square sq, t_game *game)
{
	draw_square_horizontal(sq, game);
	draw_square_vertical(sq, game);
}
