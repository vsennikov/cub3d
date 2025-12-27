/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:31 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:36 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_textures(t_data *data)
{
	if (data->map->no)
		free(data->map->no);
	if (data->map->so)
		free(data->map->so);
	if (data->map->we)
		free(data->map->we);
	if (data->map->ea)
		free(data->map->ea);
}

void	free_map_array(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_err_par(char *msg, t_data *data, int fd)
{
	if (data)
	{
		if (data->parsed_file)
			free_parsed_file(data->parsed_file);
		if (data->map)
		{
			if (data->map->map)
				free_map_array(data->map->map);
			free_textures(data);
		}
	}
	ft_putstr_fd(msg, 2);
	if (fd > 0)
		close(fd);
	exit(EXIT_FAILURE);
}

int	all_configs_parsed(t_data *data)
{
	return (data->map->parsed_no && data->map->parsed_so && data->map->parsed_we
		&& data->map->parsed_ea && data->map->parsed_f && data->map->parsed_c);
}
