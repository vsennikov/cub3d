/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:13:44 by vsenniko          #+#    #+#             */
/*   Updated: 2025/12/27 17:14:51 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 1280
# define HEIGHT 720
# define DEBUG 0
# define PI 3.14159265359
# define BLOCK 64
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_texture;

typedef struct s_map
{
	char			**map;
	int				height;
	int				width;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	t_texture		tex_no;
	t_texture		tex_so;
	t_texture		tex_ea;
	t_texture		tex_we;
	// Parsing flags
	int				parsed_no;
	int				parsed_so;
	int				parsed_we;
	int				parsed_ea;
	int				parsed_f;
	int				parsed_c;
	// Temp colors for parsing
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	// Temp player info for parsing
	int				player_x;
	int				player_y;
	char			player_dir;
}					t_map;

typedef struct s_player
{
	float			x_player;
	float			y_player;
	float			angle;
	float			angle_speed;
	float			fov;
	int				speed;
	bool			player_up;
	bool			player_down;
	bool			player_left;
	bool			player_right;
	bool			left_player_rot;
	bool			right_player_rot;
}					t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				size_line;
	int				endian;
	t_player		player;
	t_map			mappy;
}					t_game;

// Data struct for parser compatibility
typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	char		**parsed_file;
}					t_data;

typedef struct s_ray
{
	float			dir_x;
	float			dir_y;
	float			pos_x;
	float			pos_y;
	float			distance;
}					t_ray;

typedef struct s_dda
{
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	float			perp_wall_dist;
	float			wall_x;
}					t_dda;

typedef struct s_wall
{
	int				height;
	int				start_y;
	int				end_y;
	int				color;
	t_texture		*texture;
	int				tex_x;
}					t_wall;

typedef struct s_square
{
	int				x;
	int				y;
	int				size;
	int				color;
}					t_square;

/* Init functions */
void				ft_init_game(t_game *game);
void				ft_init_player(t_player *player);
void				ft_init_map(t_game *game);
float				init_player_direction(char orientation);

/* Texture functions */
void				load_textures(t_game *game);
void				load_texture(t_texture *tex, char *path, t_game *game);
void				select_texture(t_dda *dda, t_wall *wall, t_game *game);
unsigned int		get_texture_pixel(t_texture *tex, int x, int y);

/* Render functions */
int					draw_loop(t_game *game);
void				draw_floor_ceiling(t_game *game);
void				cast_ray(t_game *game, int x);
void				cast_ray_dda(t_game *game, int x);
void				init_dda(t_dda *dda, t_player *player, float angle);
void				perform_dda(t_dda *dda, t_game *game);
void				calculate_wall_dda(t_dda *dda, t_wall *wall,
						float angle_diff);
void				calculate_wall(t_ray *ray, t_wall *wall, t_game *game);
void				draw_wall_slice(t_wall *wall, int x, t_game *game);

/* Draw functions */
void				draw_square(t_square sq, t_game *game);
void				draw_map(t_game *game);

/* Collision functions */
bool				touch(float px, float py, t_game *game);
bool				check_collision(float px, float py, t_game *game);

/* Movement functions */
void				move_player(t_game *game);
void				apply_movement(t_player *p, float cos_a, float sin_a,
						t_game *g);

/* Input functions */
int					key_press(int keysym, t_game *game);
int					key_release(int keysym, t_game *game);

/* Math utils */
float				calculate_distance(float x, float y);
float				fixed_distance(t_player *p, float x, float y);

/* Pixel utils */
void				put_pixel(int x, int y, int color, t_game *game);

/* Map functions */
char				**getmap(t_game *game);

/* Cleanup functions */
int					close_window(t_game *game);
void				ft_free_mlx_allocation(t_game *game);

/* Error handling functions */
// void			error_exit(char *message, t_game *game); // This
// conflicts with parser's error_exit. Will handle.
void				error_mlx_init(t_game *game);
void				error_window(t_game *game);
void				error_image(t_game *game);
void				error_texture(char *texture_path, t_game *game);

// --- Parsing Prototypes ---

// --- Parsing Prototypes ---

int					name_validation(char *name);
void				error_exit(char *msg, t_game *game);
// letting conflict exist to see errors or renaming in parser files.

int					parser(t_data *data, char *file);
void				cleanup_data(t_data *data);

// Parser file operations
char				**parse_file(int fd, t_data *data);
char				**read_file_lines(int fd, t_data *data, char **parsed_file,
						int capacity);
char				**add_line_to_array(char **parsed_file, char *line, int *i,
						int *capacity);
void				free_parsed_file(char **parsed_file);
int					is_valid_texture_file(char *path, t_data *data, int fd);
int					count_valid_map_lines(char **parsed_file, int start_idx,
						t_data *data, int fd);
void				allocate_map_memory(t_data *data, int map_lines, int fd);
void				process_all_map_lines(char **parsed_file, int start_idx,
						t_data *data, int fd, int map_lines);

// Parser memory management
void				init_map(t_data *data);
void				init_map_flags(t_data *data);
int					process_file_content(char **parsed_file, t_data *data,
						int fd);
void				free_textures(t_data *data);
void				free_map_array(char **map);
void				exit_err_par(char *msg, t_data *data, int fd);
int					all_configs_parsed(t_data *data);

// Parser utilities
char				*trim_whitespace(char *str);
char				*trim_newlines(char *str);
int					is_valid_map_char(char c);
int					check_line(char *line, char *identifier);
int					check_color_line(char *line, char *identifier);

// Parser configuration
int					parse_color_component(char *str, t_data *data, int fd);
void				parse_color(char *line, char type, t_data *data, int fd);
char				*extract_color_string(char *line);
void				parse_color_components(char **components, char type,
						t_data *data, int fd);
void				free_color_components(char **components);
void				free_components_and_exit(char **components, t_data *data,
						int fd, char *msg);
void				parse_floor_color(char **components, t_data *data, int fd);
void				parse_ceiling_color(char **components, t_data *data,
						int fd);
int					parse_component_at_index(char **components, int index,
						t_data *data, int fd);
void				parse_config_line(char *line, t_data *data, int fd);
void				handle_floor_color(char *line, t_data *data, int fd);
void				handle_ceiling_color(char *line, t_data *data, int fd);

// Parser texture handling
void				parse_texture_path(char *line, char *identifier,
						t_data *data, int fd);
char				*extract_texture_path(char *line, char *identifier,
						t_data *data, int fd);
char				**get_texture_pointer(char *identifier, t_data *data);
void				parse_no_texture(char *line, t_data *data, int fd);
void				parse_so_texture(char *line, t_data *data, int fd);
void				parse_we_texture(char *line, t_data *data, int fd);
void				parse_ea_texture(char *line, t_data *data, int fd);
int					parse_texture_line(char *line, t_data *data, int fd);
int					parse_so_textures(char *line, t_data *data, int fd);
int					parse_we_ea_textures(char *line, t_data *data, int fd);

// Parser map validation
void				validate_map_characters_and_player(t_data *data, int fd);
void				validate_map_enclosure(t_data *data, int fd);
int					is_valid_map_position(char c, int i, int j, int boundary);

// Parser map utilities
int					is_next_to_space(t_data *data, int i, int j);
void				parse_map_data(char **parsed_file, int start_idx,
						t_data *data, int fd);
void				process_map_line(char *line, t_data *data, int fd, int *i);
void				finalize_map_parsing(t_data *data, int fd, int map_height);

// Parser main phases
int					parse_config(char **parsed_file, t_data *data, int fd);
void				parse_map_phase(char **parsed_file, int start_idx,
						t_data *data, int fd);

// Conversion helper
unsigned int		rgb_to_int(int r, int g, int b);

void				init_mlx_part(t_game *game);
#endif
