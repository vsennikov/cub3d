/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void destroy_textures(t_game *game) {
  if (game->mappy.tex_no.img) {
    mlx_destroy_image(game->mlx, game->mappy.tex_no.img);
    game->mappy.tex_no.img = NULL;
  }
  if (game->mappy.tex_so.img) {
    mlx_destroy_image(game->mlx, game->mappy.tex_so.img);
    game->mappy.tex_so.img = NULL;
  }
  if (game->mappy.tex_ea.img) {
    mlx_destroy_image(game->mlx, game->mappy.tex_ea.img);
    game->mappy.tex_ea.img = NULL;
  }
  if (game->mappy.tex_we.img) {
    mlx_destroy_image(game->mlx, game->mappy.tex_we.img);
    game->mappy.tex_we.img = NULL;
  }
  // Free texture paths
  if (game->mappy.no)
    free(game->mappy.no);
  if (game->mappy.so)
    free(game->mappy.so);
  if (game->mappy.we)
    free(game->mappy.we);
  if (game->mappy.ea)
    free(game->mappy.ea);
}

static void destroy_image(t_game *game) {
  if (game->img) {
    mlx_destroy_image(game->mlx, game->img);
    game->img = NULL;
  }
}

static void destroy_window(t_game *game) {
  if (game->win) {
    mlx_destroy_window(game->mlx, game->win);
    game->win = NULL;
  }
}

int close_window(t_game *game) {
  if (game->mappy.map) {
    free_map_array(game->mappy.map);
    game->mappy.map = NULL;
  }
  destroy_textures(game);
  destroy_image(game);
  destroy_window(game);
  if (game->mlx) {
    // On Mac/OpenGL minilibx, just free(mlx) or do nothing?
    // Usually free(mlx) is acceptable if destroy_display doesn't exist.
    // But to avoid "unused function" errors if I had separate function, I
    // inline here or just skip. Partner code had free(game->mlx). I'll include
    // it.
    free(game->mlx);
    game->mlx = NULL;
  }
  exit(EXIT_SUCCESS);
}

void ft_free_mlx_allocation(t_game *game) { close_window(game); }
