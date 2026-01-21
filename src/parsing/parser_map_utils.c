/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:00 by vsenniko          #+#    #+#             */
/*   Updated: 2026/01/21 13:24:18 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_map_data(int s_index, t_data *data, int fd)
{
	int	map_lines;

	map_lines = count_valid_map_lines(s_index, data, fd);
	if (map_lines == 0)
		exit_err_par("Error: No map data found\n", data, fd);
	allocate_map_memory(data, map_lines, fd);
	process_all_map_lines(s_index, data, fd, map_lines);
	finalize_map_parsing(data, fd, map_lines);
}

void	allocate_map_memory(t_data *data, int map_lines, int fd)
{
	int	i;

	data->map->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!data->map->map)
		exit_err_par("Error: Memory allocation failed\n", data, fd);
	i = 0;
	while (i <= map_lines)
		data->map->map[i++] = NULL;
}

void	process_all_map_lines(int s_index, t_data *data, int fd, int map_lines)
{
	int		i;
	int		j;
	char	*trimmed_line;

	i = 0;
	j = s_index;
	while (data->parsed_file[j] && i < map_lines)
	{
		if (ft_strlen(data->parsed_file[j]) <= 1)
			j++;
		else
		{
			trimmed_line = trim_newlines(data->parsed_file[j]);
			if (!trimmed_line)
				exit_err_par("Error: Memory allocation failed\n", data, fd);
			data->map->map[i] = trimmed_line;
			i++;
			j++;
		}
	}
}

void	finalize_map_parsing(t_data *data, int fd, int map_height)
{
	int	i;
	int	max_width;
	int	len;

	data->map->map[map_height] = NULL;
	data->map->height = map_height;
	i = 0;
	max_width = 0;
	while (i < map_height)
	{
		len = ft_strlen(data->map->map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	data->map->width = max_width;
	validate_map_characters_and_player(data, fd);
	validate_map_enclosure(data, fd);
}

int	count_valid_map_lines(int start_idx, t_data *data, int fd)
{
	int	count;
	int	i;
	int	found_map_content;

	count = 0;
	i = start_idx;
	found_map_content = 0;
	while (data->parsed_file[i])
	{
		if (ft_strlen(data->parsed_file[i]) <= 1)
		{
			if (found_map_content)
				exit_err_par("Error: Empty line found within map data\n", data,
					fd);
		}
		else
		{
			found_map_content = 1;
			count++;
		}
		i++;
	}
	return (count);
}
