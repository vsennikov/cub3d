/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:19:53 by vsenniko          #+#    #+#             */
/*   Updated: 2025/08/05 13:00:07 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h> 

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	char		*floor_color;
	char		*ceiling_color;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	int			player_x;
	int			player_y;
	char		player_dir;
} t_map;

typedef struct s_data
{
	t_map		*map;
	void		*mlx;
	void		*mlx_win_ptr;
} t_data;


//#parsing funcs
int	name_validation(char *name);
int	parser(t_data *data, char *file);

#endif