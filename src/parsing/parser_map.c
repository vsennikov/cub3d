/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:10 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:33 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	validate_char_and_set_player(t_data *data, int i, int j, int fd)
{
	char	c;
	int		player_found;

	c = data->map->map[i][j];
	player_found = 0;
	if (!is_valid_map_char(c))
		exit_err_par("Error: Invalid character in map\n", data, fd);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		data->map->player_x = j;
		data->map->player_y = i;
		data->map->player_dir = c;
		player_found = 1;
	}
	return (player_found);
}

void	validate_map_characters_and_player(t_data *data, int fd)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			player_count += validate_char_and_set_player(data, i, j, fd);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		exit_err_par("Error: Map must contain exactly one player starting position\n",
			data, fd);
}

static int	check_position_enclosure(t_data *data, int i, int j, int fd)
{
	char	c;
	int		len;

	c = data->map->map[i][j];
	len = ft_strlen(data->map->map[i]);
	if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (i == 0 || i == data->map->height - 1 || j == 0 || j == len - 1)
		exit_err_par("Error: Map is not enclosed\n", data, fd);
	if (is_next_to_space(data, i, j))
		exit_err_par("Error: Map is not enclosed\n", data, fd);
	return (1);
}

void	validate_map_enclosure(t_data *data, int fd)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		len = ft_strlen(data->map->map[i]);
		while (j < len)
		{
			check_position_enclosure(data, i, j, fd);
			j++;
		}
		i++;
	}
}

int	is_valid_map_position(char c, int i, int j, int boundary)
{
	int	is_playable;
	int	is_border;

	is_playable = (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
	is_border = (i == 0 || i == boundary - 1 || j == 0);
	if (is_playable && is_border)
		return (0);
	return (1);
}
