#include "../cub3d.h"

void	handle_floor_color(char *line, t_data *data, int fd)
{
	if (data->map->parsed_f)
		exit_err_par("Error: Duplicate F identifier\n", data, fd);
	if (!check_color_line(line, "F"))
		exit_err_par("Error: Extra characters after F definition\n", data, fd);
	data->map->parsed_f = 1;
	parse_color(line, 'F', data, fd);
}

void	handle_ceiling_color(char *line, t_data *data, int fd)
{
	if (data->map->parsed_c)
		exit_err_par("Error: Duplicate C identifier\n", data, fd);
	if (!check_color_line(line, "C"))
		exit_err_par("Error: Extra characters after C definition\n", data, fd);
	data->map->parsed_c = 1;
	parse_color(line, 'C', data, fd);
}
