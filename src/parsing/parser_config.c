/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:35:51 by vsenniko          #+#    #+#             */
/*   Updated: 2026/01/21 15:25:35 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_color_component(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str || !*str)
		return (-1);
	if (ft_strlen(str) > 3)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > 255)
		return (-1);
	return (result);
}

void	parse_color(char *line, char type, t_data *data, int fd)
{
	char	**components;
	char	*trimmed;

	trimmed = extract_color_string(line);
	if (!trimmed)
		exit_err_par("Error: Memory allocation failed\n", data, fd);
	components = ft_split(trimmed, ',');
	free(trimmed);
	if (!components)
		exit_err_par("Error: Memory allocation failed\n", data, fd);
	parse_color_components(components, type, data, fd);
}

char	*extract_color_string(char *line)
{
	char	*color_str;

	color_str = line + 1;
	while (*color_str && (*color_str == ' ' || *color_str == '\t'))
		color_str++;
	return (trim_whitespace(color_str));
}

void	parse_color_components(char **components, char type, t_data *data,
		int fd)
{
	int	i;

	i = 0;
	while (components[i])
		i++;
	if (i != 3)
	{
		free_components_and_exit(components, data, fd,
			"Error: Invalid color format - must have exactly 3 components\n");
	}
	if (type == 'F')
		parse_floor_color(components, data, fd);
	else
		parse_ceiling_color(components, data, fd);
	free_color_components(components);
}

void	free_color_components(char **components)
{
	int	i;

	i = 0;
	while (components[i])
		free(components[i++]);
	free(components);
}
