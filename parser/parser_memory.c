#include "../cub3d.h"

void	free_textures(t_data *data)
{
	if (data->map->n_texture)
		free(data->map->n_texture);
	if (data->map->s_texture)
		free(data->map->s_texture);
	if (data->map->w_texture)
		free(data->map->w_texture);
	if (data->map->e_texture)
		free(data->map->e_texture);
}

void	free_map_array(char **map)
{
	int	i;

	if (!map)
		return;
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
			free(data->map);
		}
	}
	ft_putstr_fd(msg, 2);
	if (fd != 0)
		close(fd);
	exit(EXIT_FAILURE);
}

int	all_configs_parsed(t_data *data)
{
	return (data->map->parsed_no && data->map->parsed_so && 
		data->map->parsed_we && data->map->parsed_ea && 
		data->map->parsed_f && data->map->parsed_c);
}
