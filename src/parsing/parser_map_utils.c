#include "../../includes/cub3d.h"

int is_next_to_space(t_data *data, int i, int j) {
  if (i > 0 && j < (int)ft_strlen(data->map->map[i - 1]) &&
      data->map->map[i - 1][j] == ' ')
    return (1);
  if (i < data->map->height - 1 && j < (int)ft_strlen(data->map->map[i + 1]) &&
      data->map->map[i + 1][j] == ' ')
    return (1);
  if (j > 0 && data->map->map[i][j - 1] == ' ')
    return (1);
  if (j < (int)ft_strlen(data->map->map[i]) - 1 &&
      data->map->map[i][j + 1] == ' ')
    return (1);
  return (0);
}

void parse_map_data(char **parsed_file, int s_index, t_data *data, int fd) {
  int map_lines;

  map_lines = count_valid_map_lines(parsed_file, s_index, data, fd);
  if (map_lines == 0)
    exit_err_par("Error: No map data found\n", data, fd);
  allocate_map_memory(data, map_lines, fd);
  process_all_map_lines(parsed_file, s_index, data, fd, map_lines);
  finalize_map_parsing(data, fd, map_lines);
}

void allocate_map_memory(t_data *data, int map_lines, int fd) {
  int i;

  data->map->map = malloc(sizeof(char *) * (map_lines + 1));
  if (!data->map->map)
    exit_err_par("Error: Memory allocation failed\n", data, fd);
  i = 0;
  while (i <= map_lines)
    data->map->map[i++] = NULL;
}

void process_all_map_lines(char **parsed_file, int s_index, t_data *data,
                           int fd, int map_lines) {
  int i;
  int j;

  i = 0;
  j = s_index;
  while (parsed_file[j] && i < map_lines) {
    if (ft_strlen(parsed_file[j]) <= 1) {
      j++;
    } else {
      process_map_line(parsed_file[j], data, fd, &i);
      j++;
    }
  }
}

void process_map_line(char *line, t_data *data, int fd, int *i) {
  char *trimmed_line;

  trimmed_line = trim_newlines(line);
  if (!trimmed_line)
    exit_err_par("Error: Memory allocation failed\n", data, fd);
  data->map->map[*i] = trimmed_line;
  (*i)++;
}

void finalize_map_parsing(t_data *data, int fd, int map_height) {
  data->map->map[map_height] = NULL;
  data->map->height = map_height;
  validate_map_characters_and_player(data, fd);
  validate_map_enclosure(data, fd);
}

int count_valid_map_lines(char **parsed_file, int start_idx, t_data *data,
                          int fd) {
  int count;
  int i;
  int found_map_content;

  count = 0;
  i = start_idx;
  found_map_content = 0;
  while (parsed_file[i]) {
    if (ft_strlen(parsed_file[i]) <= 1) {
      if (found_map_content)
        exit_err_par("Error: Empty line found within map data\n", data, fd);
    } else {
      found_map_content = 1;
      count++;
    }
    i++;
  }
  return (count);
}
