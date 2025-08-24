#include "../cub3d.h"

char	**parse_file(int fd, t_data *data)
{
	char	**parsed_file;
	int		capacity;

	capacity = 100;
	parsed_file = ft_calloc(capacity, sizeof(char *));
	if (!parsed_file)
		return (NULL);
	return (read_file_lines(fd, data, parsed_file, capacity));
}

char	**read_file_lines(int fd, t_data *data, char **parsed_file, int capacity)
{
	int		file_end;
	char	*line;
	int		i;

	file_end = 0;
	i = 0;
	while (!file_end)
	{
		line = get_next_line(fd, &file_end);
		if (file_end == -1)
		{
			free_parsed_file(parsed_file);
			exit_err_par("Error: Failed to read file\n", data, fd);
		}
		if (line)
			parsed_file = add_line_to_array(parsed_file, line, &i, &capacity);
	}
	return (parsed_file);
}

char	**add_line_to_array(char **parsed_file, char *line, int *i, int *capacity)
{
	char	**temp_array;

	if (*i >= *capacity - 1)
	{
		*capacity *= 2;
		temp_array = ft_calloc(*capacity, sizeof(char *));
		if (!temp_array)
			return (NULL);
		ft_memcpy(temp_array, parsed_file, *i * sizeof(char *));
		free(parsed_file);
		parsed_file = temp_array;
	}
	parsed_file[*i] = line;
	(*i)++;
	return (parsed_file);
}

void	free_parsed_file(char **parsed_file)
{
	int	i;

	if (!parsed_file)
		return ;
	i = 0;
	while (parsed_file[i])
	{
		free(parsed_file[i]);
		i++;
	}
	free(parsed_file);
}

int	is_valid_texture_file(char *path, t_data *data, int fd)
{
	int	texture_fd;

	texture_fd = open(path, O_RDONLY);
	if (texture_fd < 0)
	{
		free(path);
		exit_err_par("Error: Texture file does not exist or is not readable\n", 
			data, fd);
	}
	close(texture_fd);
	return (1);
}
