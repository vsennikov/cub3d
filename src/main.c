#include "../includes/cub3d.h"

int main(int argc, char **argv) {
  t_game game;
  t_data data;

  if (argc != 2) {
    ft_putstr_fd("Error\nUsage: ./cub3D <map.cub>\n", 2);
    return (1);
  }

  // 1. Initialize structures to safe defaults
  ft_bzero(&game, sizeof(t_game));
  ft_init_game(&game); // Allocates mlx, win, img

  // 2. Setup data wrapper for parsing
  data.map = &game.mappy;
  data.player = &game.player;
  data.mlx = game.mlx;
  data.parsed_file = NULL;

  // 3. Parse file (fills game.mappy and game.player)
  parser(&data, argv[1]);

  // 4. Load textures (now that paths are known)
  load_textures(&game);

  // 5. Launch game loop
  mlx_hook(game.win, 2, 1L << 0, key_press, &game);
  mlx_hook(game.win, 3, 1L << 1, key_release, &game);
  mlx_hook(game.win, 17, 1L << 0, &close_window, &game);
  mlx_loop_hook(game.mlx, draw_loop, &game);
  mlx_loop(game.mlx);

  return (0);
}
