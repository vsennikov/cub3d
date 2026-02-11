/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2026/02/09 16:23:41 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_exit(char *message, t_game *game)
{
	printf("Error\n%s\n", message);
	if (game)
		close_window(game);
	else
		exit(EXIT_FAILURE);
}

void	error_mlx_init(t_game *game)
{
	if (game->mappy.map)
	{
		free_map_array(game->mappy.map);
		game->mappy.map = NULL;
	}
	destroy_textures(game);
	error_exit("Failed to initialize MLX", NULL);
	(void)game;
}

void	error_window(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->mappy.map)
	{
		free_map_array(game->mappy.map);
		game->mappy.map = NULL;
	}
	destroy_textures(game);
	error_exit("Failed to create window", NULL);
}

void	error_image(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	if (game->mappy.map)
	{
		free_map_array(game->mappy.map);
		game->mappy.map = NULL;
	}
	destroy_textures(game);
	error_exit("Failed to create image", NULL);
}

void	error_texture(char *texture_path, t_game *game)
{
	printf("Error\nFailed to load texture: %s\n", texture_path);
	close_window(game);
}
