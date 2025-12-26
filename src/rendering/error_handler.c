/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void error_exit(char *message, t_game *game) {
  printf("Error\n%s\n", message);
  if (game)
    ft_free_mlx_allocation(game);
  else
    exit(EXIT_FAILURE);
}

void error_mlx_init(t_game *game) {
  error_exit("Failed to initialize MLX", NULL);
  (void)game;
}

void error_window(t_game *game) {
  if (game->mlx) {
    free(game->mlx);
  }
  error_exit("Failed to create window", NULL);
}

void error_image(t_game *game) {
  if (game->win)
    mlx_destroy_window(game->mlx, game->win);
  if (game->mlx) {
    free(game->mlx);
  }
  error_exit("Failed to create image", NULL);
}

void error_texture(char *texture_path, t_game *game) {
  char *error_msg;
  char *prefix;

  prefix = "Failed to load texture: ";
  error_msg = malloc(strlen(prefix) + strlen(texture_path) + 1);
  if (!error_msg)
    error_exit("Memory allocation failed", game);
  strcpy(error_msg, prefix);
  strcat(error_msg, texture_path);
  printf("Error\n%s\n", error_msg);
  free(error_msg);
  ft_free_mlx_allocation(game);
}
