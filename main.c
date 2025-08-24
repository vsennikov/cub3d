#include "cub3d.h"


void	cleanup_data(t_data *data)
{
	if (data && data->map)
	{
		if (data->parsed_file)
			free_parsed_file(data->parsed_file);
		if (data->map->map)
			free_map_array(data->map->map);
		free_textures(data);
		free(data->map);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_putstr_fd("Usage: ./cub3d <map_file.cub>\n", 2), 1);
	name_validation(argv[1]);
	data.map = malloc(sizeof(t_map));
	if (!data.map)
		error_exit("Memory allocation for map failed");
	ft_bzero(data.map, sizeof(t_map));
	data.parsed_file = NULL;
	parser(&data, argv[1]);
	cleanup_data(&data);
	return (0);
}
