/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferny <bferny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:12:18 by bferny            #+#    #+#             */
/*   Updated: 2022/04/02 15:26:50 by bferny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <math.h>

# define WINDOW_WIDTH 1020
# define WINDOW_HEIGHT 1080
# define SIZE 64
# define NOTSET -1
# define CR_CHAR 1
# define CR_SIGN 2
# define GC 0x990099
# define SOUTH 0
# define NORTH 1
# define WEST 2
# define EAST 3
# define NMBR_OF_TEXT 4

typedef struct s_line
{
	int						bot;
	int						top;
	int						x_pos;
	double					column_height;
}							t_line;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_texture
{
	void					*img;
	int						width;
	int						height;
	int						text_x;
	int						text_y;
	int						bits_per_pixel;
	int						line_length;
	char					*addr;
	int						endian;
}							t_texture;

typedef struct s_map
{
	char		**my_map;
	t_texture	*texture;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_color		floor;
	t_color		ceil;
	int			height;
	int			width;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}t_map;

typedef struct s_iter
{
	int	x;
	int	y;
	int	border;
	int	start;
	int	height;
}				t_iter;

typedef struct s_win
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*addr;
	int		line_l;
	int		bpp;
	int		en;

}				t_win;

typedef struct s_player
{
	int			x;
	int			y;
	float		dir;
}				t_player;

typedef struct s_plr
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
	float		delta_x;
	float		delta_y;
	int			map_x;
	int			map_y;
	int			wall;
	float		wall_x;
	float		length;
	float		perp_length;
}				t_plr;

typedef struct s_all
{
	t_win		*win;
	t_map		*map;
	t_plr		*plr;
	t_player	*player;
	int			floor_color;
	int			ceil_color;
}				t_all;

void	ft_error(char *str); //
float	vertical(t_all *game, double dg, t_plr *ray); //
float	horizontal(t_all *game, double dg, t_plr *ray);//
int		ft_look_up(float dg);//
int		ft_look_right(float dg);//
float	normal_deg(float dg);//
double	ft_dg_to_rad(double degrees);//
float	crossing(t_all *all, t_plr *ray, float distance);//
void	ft_sn_wall(t_plr *res, t_plr ray, float dist, float dg);//
void	ft_we_wall(t_plr *res, t_plr ray, float dist, float dg);//
void	ft_line(t_all *all, t_plr ray, t_line line);//
void	ft_texture(t_all *all, t_plr ray, t_line line);//
void	ft_mlx_pixel_put(t_win *win, int x, int y, int color);//
int		raycaster(t_all *all);
float	get_vector_length(t_all *game, t_plr ray);
int		get_texture_color(t_texture *texture, int x, int y);
int		ft_rgb_to_int(unsigned char r, unsigned char g, unsigned char b);//
int		ft_check_wall(t_all *all, float side_dir);//
void	ft_text_error(t_texture *text, char *path, t_all *all);//
void	textures_init(t_all *all);
float	one_ray_angle(int fov, int width);
//parser
int		map_checker(char *str, t_map *map); //
int		char_checker(char c); //
void	find_unit(t_player	*plr, char **my_map);
void	find_unit_help(t_player *plr, t_iter it, char **my_map);
void	draw(t_all *all); //
void	actions(int keycode, int x, int y, t_all *all);
void	*free_array(char **arr);
void	scale(t_win *win, int color, int x1, int y1);
void	draw_player(t_all *all, t_plr *pl);
void	free_map(char **map);
int		cust_atoi(char *str);
char	**parsing(int file, char *file_name);
void	ft_rgb(char *str, t_color *color);//
void	ft_path(char *str, char **new);//
void	check_my_map(char **map);
void	ft_map(t_map *map, char **map_str);//
void	main_add(t_all all);
int		close_hook(t_all *all);
int		key_hook(int keycode, t_all *all);
#endif
