/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 06:01:01 by chmarque          #+#    #+#             */
/*   Updated: 2025/12/27 17:09:50 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	calculate_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_distance(t_player *p, float x, float y)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x - p->x_player;
	delta_y = y - p->y_player;
	angle = atan2(delta_y, delta_x) - p->angle;
	fix_dist = calculate_distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}
