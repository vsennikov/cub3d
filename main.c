/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:30:49 by vsenniko          #+#    #+#             */
/*   Updated: 2025/08/17 10:35:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_init(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("Memory allocation for map failed\n", 2);
		exit(1);
	}
	data->mlx = NULL;
	data->mlx_win_ptr = NULL;
	data->map->height = 2;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./cub3d <map_file.cub>\n", 2), 1);
	name_validation(argv[1]);
	data_init(&data);
	return (0);
}
