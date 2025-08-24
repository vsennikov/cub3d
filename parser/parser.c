#include "../cub3d.h"

int	parser(t_data *data, char *file)
{
	int		fd;
	char	**parsed_file;

	init_map(data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err_par("Error: Cannot open file\n", data, fd);
	parsed_file = parse_file(fd, data);
	if (!parsed_file)
		exit_err_par("Error: Failed to parse file\n", data, fd);
	data->parsed_file = parsed_file;
	return (process_file_content(parsed_file, data, fd));
}

int	process_file_content(char **parsed_file, t_data *data, int fd)
{
	int	i;

	i = parse_config(parsed_file, data, fd);
	parse_map_data(parsed_file, i, data, fd);
	data->parsed_file = NULL;
	free_parsed_file(parsed_file);
	close(fd);
	return (1);
}

int	parse_config(char **parsed_file, t_data *data, int fd)
{
	int	i;

	i = 0;
	while (parsed_file[i] && !all_configs_parsed(data))
	{
		if (ft_strlen(parsed_file[i]) > 1)
			parse_config_line(parsed_file[i], data, fd);
		i++;
	}
	if (!all_configs_parsed(data))
		exit_err_par("Error: Missing configuration elements\n", data, fd);
	return (i);
}

void	init_map_flags(t_data *data)
{
	data->map->parsed_no = 0;
	data->map->parsed_so = 0;
	data->map->parsed_we = 0;
	data->map->parsed_ea = 0;
	data->map->parsed_f = 0;
	data->map->parsed_c = 0;
}

void	init_map(t_data *data)
{
	init_map_flags(data);
	data->map->n_texture = NULL;
	data->map->s_texture = NULL;
	data->map->w_texture = NULL;
	data->map->e_texture = NULL;
	data->map->map = NULL;
	data->map->player_x = -1;
	data->map->player_y = -1;
	data->map->player_dir = 0;
}
