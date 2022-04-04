/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:48:42 by cdiks             #+#    #+#             */
/*   Updated: 2022/04/04 11:41:42 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# define TILE_SIZE 32

typedef struct s_map {
	char			data;
	int				x;
	int				y;
	struct s_map	*next;
}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*image;
	void	*mlx_window;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
}				t_data;

typedef struct s_player {
	t_data		mlx;
	int			y;
	int			x;
}				t_player;

typedef struct s_wall {
	t_data		mlx;
}				t_wall;

typedef struct s_floor {
	t_data		mlx;
}				t_floor;

typedef struct s_collectible {
	t_data		mlx;
}				t_collectible;

typedef struct s_exit {
	t_data		mlx;
}				t_exit;

typedef struct s_xpm {
	t_floor			floor;
	t_wall			wall;
	t_exit			exit;
	t_player		player;
	t_collectible	collectible;
	t_data			data;
	t_map			map;

}				t_xpm;

typedef enum s_keys {
	UP = 13,
	LEFT = 0,
	RIGHT = 1,
	DOWN = 2,
	ESC = 53,
}	t_keys;

typedef enum s_map_obj {
	EMPTY = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}	t_map_obj;

unsigned int	get_pixel_from_xpm(t_data *xpm, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data			initialize_game(t_map *map);
int				close_window(int keycode, t_data *data);
int				key_hook(int keycode, t_data *data);
void			read_map(t_map **map, char *file);
void			add_to_list(t_map **head, char line, int x, int y);
void			print_list(t_map *list);
void			create_wall(t_data *data, t_map *map);
void			draw_map(t_data *data, t_map *map, t_xpm *xpm);
void			draw_tile(int x, int y, t_data *data, t_data *xpm);
void			check_map(t_map **map);
void			check_letters(t_map **map);
void			check_other_chars(t_map **map);
void			check_rectangle(t_map **map);
void			check_wall(t_map **map);
int				highest_y(t_map *map);
int				highest_x(t_map *map);
void			check_ver_lines(t_map **map);
void			check_hor_lines(t_map **map);
void			initialize_images(t_data *data, t_xpm *xpm);
void			get_addresses(t_data *data, t_xpm *xpm);
int				length(t_map *map);
int				width(t_map *map);
void			move(int move);
//void			check_valid_file(char **argv);

#endif