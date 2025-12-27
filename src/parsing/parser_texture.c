/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:40 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:10:42 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_no_texture(char *line, t_data *data, int fd)
{
	if (data->map->parsed_no)
		exit_err_par("Error: Duplicate NO identifier\n", data, fd);
	if (!check_line(line, "NO"))
		exit_err_par("Error: Extra characters after NO definition\n", data, fd);
	parse_texture_path(line, "NO", data, fd);
	data->map->parsed_no = 1;
}

void	parse_so_texture(char *line, t_data *data, int fd)
{
	if (data->map->parsed_so)
		exit_err_par("Error: Duplicate SO identifier\n", data, fd);
	if (!check_line(line, "SO"))
		exit_err_par("Error: Extra characters after SO definition\n", data, fd);
	parse_texture_path(line, "SO", data, fd);
	data->map->parsed_so = 1;
}

void	parse_we_texture(char *line, t_data *data, int fd)
{
	if (data->map->parsed_we)
		exit_err_par("Error: Duplicate WE identifier\n", data, fd);
	if (!check_line(line, "WE"))
		exit_err_par("Error: Extra characters after WE definition\n", data, fd);
	parse_texture_path(line, "WE", data, fd);
	data->map->parsed_we = 1;
}

void	parse_ea_texture(char *line, t_data *data, int fd)
{
	if (data->map->parsed_ea)
		exit_err_par("Error: Duplicate EA identifier\n", data, fd);
	if (!check_line(line, "EA"))
		exit_err_par("Error: Extra characters after EA definition\n", data, fd);
	parse_texture_path(line, "EA", data, fd);
	data->map->parsed_ea = 1;
}
