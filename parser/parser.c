#include "../cub3d.h"
#include <fcntl.h>

void free_textures(t_data *data)
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

void exit_err_par(char *msg, t_data *data, int fd)
{
	int i;

	i = 0;
	if (data)
	{
		if (data->map)
		{
			if (data->map->map)
			{
				while (data->map->map[i])
				{
					free(data->map->map[i]);
					i++;
				}
				free(data->map->map);
			}
			free_textures(data);
			free(data->map);
		}
	}
	ft_putstr_fd(msg, 2);
	if (fd != 0)
		close(fd);
	exit(EXIT_FAILURE);
}

int calculate_size(char *file, t_data *data)
{
	char	*line;
	int		fd;
	int		i;
	int		ended;

	ended = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err_par("wrong file permission", data, fd);
	line = get_next_line(fd, &ended);
	if (ended == -1)
		exit_err_par("gnl failed inside calculate_size", data, fd);
	i = 0;
	while (!ended)
	{
		if (ft_strlen(line) > 1)
			i++;
		free(line);
		line = get_next_line(fd, &ended);
		if (ended == -1)
			exit_err_par("inside calculate_size", data, fd);
	}
	close(fd);
	return (i);
}

char **parse_file(char *file)
{
	int		file_end;
	char	*line;
	char	**parsed_file;
	int		fd;
	int		i;

	file_end = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err_par("wrong file permission", NULL, fd);
	parsed_file = ft_calloc(calculate_size(file, NULL) + 1, sizeof(char *));
	while (!file_end)
	{
		line = get_next_line(fd, &file_end);
		if (file_end == -1)
			exit_err_par("gnl failed inside parse_file", NULL, fd);
		if (line && ft_strlen(line) > 1)
			parsed_file[i++] = line;
		else if (line)
			free(line);
	}
	return (close(fd), parsed_file);
}
int	parser(t_data *data, char *file)
{
	int fd;
	char *line;
	char **parsed_file;
	int i;

	parsed_file = parse_file(file);

}