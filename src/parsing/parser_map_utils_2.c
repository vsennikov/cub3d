/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:11:31 by vsenniko          #+#    #+#             */
/*   Updated: 2026/01/21 13:11:43 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_next_to_space(t_data *data, int i, int j)
{
	if (i > 0 && j < (int)ft_strlen(data->map->map[i - 1]) && data->map->map[i
			- 1][j] == ' ')
		return (1);
	if (i < data->map->height - 1 && j < (int)ft_strlen(data->map->map[i + 1])
		&& data->map->map[i + 1][j] == ' ')
		return (1);
	if (j > 0 && data->map->map[i][j - 1] == ' ')
		return (1);
	if (j < (int)ft_strlen(data->map->map[i]) - 1 && data->map->map[i][j
		+ 1] == ' ')
		return (1);
	return (0);
}
