/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:35:45 by vsenniko          #+#    #+#             */
/*   Updated: 2026/01/21 13:43:16 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_components_and_exit(char **components, t_data *data, int fd,
		char *msg)
{
	int	i;

	i = 0;
	if (components)
	{
		while (components[i])
			free(components[i++]);
		free(components);
	}
	exit_err_par(msg, data, fd);
}

void	parse_floor_color(char **components, t_data *data, int fd)
{
	data->map->floor_r = parse_component_at_index(components, 0, data, fd);
	data->map->floor_g = parse_component_at_index(components, 1, data, fd);
	data->map->floor_b = parse_component_at_index(components, 2, data, fd);
}

void	parse_ceiling_color(char **components, t_data *data, int fd)
{
	data->map->ceiling_r = parse_component_at_index(components, 0, data, fd);
	data->map->ceiling_g = parse_component_at_index(components, 1, data, fd);
	data->map->ceiling_b = parse_component_at_index(components, 2, data, fd);
}

int	parse_component_at_index(char **components, int index, t_data *data, int fd)
{
	char	*comp_trimmed;
	int		result;

	comp_trimmed = trim_whitespace(components[index]);
	if (!comp_trimmed)
		free_components_and_exit(components, data, fd,
			"Error: Memory allocation failed\n");
	result = parse_color_component(comp_trimmed, data, fd);
	free(comp_trimmed);
	if (result == -1)
		free_components_and_exit(components, data, fd,
			"Error: Invalid color format - component out of range\n");
	return (result);
}

void	parse_config_line(char *line, t_data *data, int fd)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_no_texture(line, data, fd);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_so_texture(line, data, fd);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_we_texture(line, data, fd);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_ea_texture(line, data, fd);
	else if (ft_strncmp(line, "F ", 2) == 0)
		handle_floor_color(line, data, fd);
	else if (ft_strncmp(line, "C ", 2) == 0)
		handle_ceiling_color(line, data, fd);
	else
		exit_err_par("Error: Invalid configuration line\n", data, fd);
}
