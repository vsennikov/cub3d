/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:00:00 by chmarque          #+#    #+#             */
/*   Updated: 2026/02/17 17:15:53 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_texture_to_null(t_texture *tex)
{
	tex->img = NULL;
	tex->addr = NULL;
	tex->width = 0;
	tex->height = 0;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
}

void	load_texture(t_texture *tex, char *path, t_game *game)
{
	init_texture_to_null(tex);
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		error_texture(path, game);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(game->mlx, tex->img);
		tex->img = NULL;
		error_texture(path, game);
	}
}

void	load_textures(t_game *game)
{
	load_texture(&game->mappy.tex_no, game->mappy.no, game);
	load_texture(&game->mappy.tex_so, game->mappy.so, game);
	load_texture(&game->mappy.tex_ea, game->mappy.ea, game);
	load_texture(&game->mappy.tex_we, game->mappy.we, game);
}

unsigned int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;
	int		index;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	index = y * tex->line_len + x * (tex->bpp / 8);
	pixel = tex->addr + index;
	return (*(unsigned int *)pixel);
}

void	mlx_destroy_texture(t_game *game)
{
	if (game->mappy.tex_no.img)
	{
		mlx_destroy_image(game->mlx, game->mappy.tex_no.img);
		game->mappy.tex_no.img = NULL;
	}
	if (game->mappy.tex_so.img)
	{
		mlx_destroy_image(game->mlx, game->mappy.tex_so.img);
		game->mappy.tex_so.img = NULL;
	}
	if (game->mappy.tex_ea.img)
	{
		mlx_destroy_image(game->mlx, game->mappy.tex_ea.img);
		game->mappy.tex_ea.img = NULL;
	}
	if (game->mappy.tex_we.img)
	{
		mlx_destroy_image(game->mlx, game->mappy.tex_we.img);
		game->mappy.tex_we.img = NULL;
	}
}
