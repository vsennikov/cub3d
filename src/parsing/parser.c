/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:49 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:48 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	convert_data(t_data *data)
{
	data->map->color_floor = rgb_to_int(data->map->floor_r, data->map->floor_g,
			data->map->floor_b);
	data->map->color_ceiling = rgb_to_int(data->map->ceiling_r,
			data->map->ceiling_g, data->map->ceiling_b);
	if (data->map->player_x != -1)
	{
		data->player->x_player = data->map->player_x * BLOCK + BLOCK / 2.0;
		data->player->y_player = data->map->player_y * BLOCK + BLOCK / 2.0;
		data->player->angle = init_player_direction(data->map->player_dir);
		data->player->speed = 3;
		data->player->angle_speed = 0.03;
		data->player->fov = PI / 3;
		data->player->player_up = false;
		data->player->player_down = false;
		data->player->player_left = false;
		data->player->player_right = false;
		data->player->left_player_rot = false;
		data->player->right_player_rot = false;
	}
}

int	parser(t_data *data, char *file)
{
	int		fd;
	char	**parsed_file;

	init_map(data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err_par("Error: Cannot open file\n", NULL, 0);
	if (fd < 0)
		exit_err_par("Error: Cannot open file\n", data, fd);
	parsed_file = parse_file(fd, data);
	if (!parsed_file)
		exit_err_par("Error: Failed to parse file\n", data, fd);
	data->parsed_file = parsed_file;
	process_file_content(parsed_file, data, fd);
	convert_data(data);
	return (1);
}

int	process_file_content(char **parsed_file, t_data *data, int fd)
{
	int	i;

	i = parse_config(parsed_file, data, fd);
	parse_map_data(parsed_file, i, data, fd);
	data->parsed_file = NULL;
	free_parsed_file(parsed_file);
	close(fd);
	return (1);
}

int	parse_config(char **parsed_file, t_data *data, int fd)
{
	int	i;

	i = 0;
	while (parsed_file[i] && !all_configs_parsed(data))
	{
		if (ft_strlen(parsed_file[i]) > 1)
			parse_config_line(parsed_file[i], data, fd);
		i++;
	}
	if (!all_configs_parsed(data))
		exit_err_par("Error: Missing configuration elements\n", data, fd);
	return (i);
}

void	init_map_flags(t_data *data)
{
	data->map->parsed_no = 0;
	data->map->parsed_so = 0;
	data->map->parsed_we = 0;
	data->map->parsed_ea = 0;
	data->map->parsed_f = 0;
	data->map->parsed_c = 0;
}

void	init_map(t_data *data)
{
	init_map_flags(data);
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->we = NULL;
	data->map->ea = NULL;
	data->map->map = NULL;
	data->map->player_x = -1;
	data->map->player_y = -1;
	data->map->player_dir = 0;
}
