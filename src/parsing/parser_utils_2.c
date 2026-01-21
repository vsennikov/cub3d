/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:12:56 by vsenniko          #+#    #+#             */
/*   Updated: 2026/01/21 13:14:01 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

unsigned int	rgb_to_int(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}
