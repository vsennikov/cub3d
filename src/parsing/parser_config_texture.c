/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:35:34 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:19 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_texture_path(char *line, char *identifier, t_data *data, int fd)
{
	char	*path;
	char	**path_ptr;

	path = extract_texture_path(line, identifier, data, fd);
	is_valid_texture_file(path, data, fd);
	path_ptr = get_texture_pointer(identifier, data);
	*path_ptr = path;
}

char	*extract_texture_path(char *line, char *identifier, t_data *data,
		int fd)
{
	char	*path_start;
	char	*path;

	path_start = line + ft_strlen(identifier);
	while (*path_start && (*path_start == ' ' || *path_start == '\t'))
		path_start++;
	path = trim_whitespace(path_start);
	if (!path || !*path)
	{
		if (path)
			free(path);
		exit_err_par("Error: Missing texture path\n", data, fd);
	}
	return (path);
}

char	**get_texture_pointer(char *identifier, t_data *data)
{
	if (ft_strncmp(identifier, "NO", 2) == 0)
		return (&data->map->no);
	else if (ft_strncmp(identifier, "SO", 2) == 0)
		return (&data->map->so);
	else if (ft_strncmp(identifier, "WE", 2) == 0)
		return (&data->map->we);
	else
		return (&data->map->ea);
}
