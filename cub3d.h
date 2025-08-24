#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h> 
#include <fcntl.h>

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceiling_r;
	int			ceiling_g;
	int			ceiling_b;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	int			player_x;
	int			player_y;
	char		player_dir;
	int			parsed_no;
	int			parsed_so;
	int			parsed_we;
	int			parsed_ea;
	int			parsed_f;
	int			parsed_c;
} t_map;

typedef struct s_data
{
	t_map		*map;
	void		*mlx;
	void		*mlx_win_ptr;
	char		**parsed_file;
} t_data;

//#parsing funcs
int		name_validation(char *name);
void	error_exit(char *msg);
int		parser(t_data *data, char *file);
void	cleanup_data(t_data *data);

// Parser file operations
char	**parse_file(int fd, t_data *data);
char	**read_file_lines(int fd, t_data *data, char **parsed_file, int capacity);
char	**add_line_to_array(char **parsed_file, char *line, int *i, int *capacity);
void	free_parsed_file(char **parsed_file);
int		is_valid_texture_file(char *path, t_data *data, int fd);
int		count_valid_map_lines(char **parsed_file, int start_idx, t_data *data, int fd);
void	allocate_map_memory(t_data *data, int map_lines, int fd);
void	process_all_map_lines(char **parsed_file, int start_idx, t_data *data, int fd, int map_lines);

// Parser memory management
void	init_map(t_data *data);
void	init_map_flags(t_data *data);
int		process_file_content(char **parsed_file, t_data *data, int fd);
void	free_textures(t_data *data);
void	free_map_array(char **map);
void	exit_err_par(char *msg, t_data *data, int fd);
int		all_configs_parsed(t_data *data);

// Parser utilities
char	*trim_whitespace(char *str);
char	*trim_newlines(char *str);
int		is_valid_map_char(char c);
int		check_line(char *line, char *identifier);
int		check_color_line(char *line, char *identifier);

// Parser configuration
int		parse_color_component(char *str, t_data *data, int fd);
void	parse_color(char *line, char type, t_data *data, int fd);
char	*extract_color_string(char *line);
void	parse_color_components(char **components, char type, t_data *data, int fd);
void	free_color_components(char **components);
void	free_components_and_exit(char **components, t_data *data, int fd, char *msg);
void	parse_floor_color(char **components, t_data *data, int fd);
void	parse_ceiling_color(char **components, t_data *data, int fd);
int		parse_component_at_index(char **components, int index, t_data *data, int fd);
void	parse_config_line(char *line, t_data *data, int fd);
void	handle_floor_color(char *line, t_data *data, int fd);
void	handle_ceiling_color(char *line, t_data *data, int fd);

// Parser texture handling
void	parse_texture(char *line, char *identifier, t_data *data, int fd);
char	*extract_texture_path(char *line, char *identifier, t_data *data, int fd);
char	**get_texture_pointer(char *identifier, t_data *data);
void	parse_no_texture(char *line, t_data *data, int fd);
void	parse_so_texture(char *line, t_data *data, int fd);
void	parse_we_texture(char *line, t_data *data, int fd);
void	parse_ea_texture(char *line, t_data *data, int fd);
int		parse_texture_line(char *line, t_data *data, int fd);
int		parse_so_textures(char *line, t_data *data, int fd);
int		parse_we_ea_textures(char *line, t_data *data, int fd);

// Parser map validation
void	validate_map_characters_and_player(t_data *data, int fd);
void	validate_map_enclosure(t_data *data, int fd);
int		is_valid_map_position(char c, int i, int j, int boundary);

// Parser map utilities
int		is_next_to_space(t_data *data, int i, int j);
void	parse_map_data(char **parsed_file, int start_idx, t_data *data, int fd);
void	process_map_line(char *line, t_data *data, int fd, int *i);
void	finalize_map_parsing(t_data *data, int fd, int map_height);

// Parser main phases
int		parse_config(char **parsed_file, t_data *data, int fd);
void	parse_map_phase(char **parsed_file, int start_idx, t_data *data, int fd);

#endif