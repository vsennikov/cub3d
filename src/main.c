/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:37:35 by vsenniko          #+#    #+#             */
/*   Updated: 2026/02/11 19:29:45 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D <map.cub>\n", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	ft_init_game(&game);
	data.map = &game.mappy;
	data.player = &game.player;
	name_validation(argv[1]);
	parser(&data, argv[1]);
	init_mlx_part(&game);
	data.mlx = game.mlx;
	data.parsed_file = NULL;
	load_textures(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 1L << 0, &close_window, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
