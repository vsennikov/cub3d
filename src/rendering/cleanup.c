/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2026/02/09 15:11:39 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_textures(t_game *game)
{
	mlx_destroy_texture(game);
	if (game->mappy.no)
		free(game->mappy.no);
	if (game->mappy.so)
		free(game->mappy.so);
	if (game->mappy.we)
		free(game->mappy.we);
	if (game->mappy.ea)
		free(game->mappy.ea);
}

static void	destroy_image(t_game *game)
{
	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
}

static void	destroy_window(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}

static void	destroy_display(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	close_window(t_game *game)
{
	if (game->mappy.map)
	{
		free_map_array(game->mappy.map);
		game->mappy.map = NULL;
	}
	destroy_textures(game);
	destroy_image(game);
	destroy_window(game);
	destroy_display(game);
	exit(EXIT_SUCCESS);
}
