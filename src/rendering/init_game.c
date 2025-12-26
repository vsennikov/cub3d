/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/18 00:00:00 by chmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void init_mlx(t_game *game) {
  game->mlx = mlx_init();
  if (!game->mlx)
    error_mlx_init(game);
  game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cube3D");
  if (!game->win)
    error_window(game);
}

static void init_image(t_game *game) {
  game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
  if (!game->img)
    error_image(game);
  game->addr =
      mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
  if (!game->addr)
    error_image(game);
  // Initial image is black, no need to put it yet? Or clear window
  // mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
  // Partner had this:
  // mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void ft_init_game(t_game *game) {
  ft_init_player(&game->player);
  ft_init_map(game);
  init_mlx(game);
  // load_textures(game); // MOVED TO MAIN after parsing
  init_image(game);
}

void ft_init_map(t_game *game) {
  // Defaults, will be overwritten by parser
  game->mappy.map = NULL;
  game->mappy.width = 0;
  game->mappy.height = 0;
  game->mappy.color_ceiling = 0;
  game->mappy.color_floor = 0;
  game->mappy.no = NULL;
  game->mappy.so = NULL;
  game->mappy.we = NULL;
  game->mappy.ea = NULL;
}
