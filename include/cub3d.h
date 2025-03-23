/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:54:58 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 22:52:56 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H
# define W_HEIGHT 480
# define W_WIDTH 640
# define BLOCK_SIZE 600
# define TEXTURE_SIZE 64
# define MOVE_STEP
# define TURN_STEP
# define PI 3.141592653589793
# define FOV PI / 3.0
# define MALLOC_ERROR "Memory allocation error"
# define XSERVER_ERROR "Cannot start xlib server"
# include "mlx.h"

typedef struct s_cub3d			t_cub3d;
typedef struct s_mlx			t_mlx;
typedef struct s_config			t_config;
typedef struct s_pixel			t_pixel;
typedef struct s_key			t_key;
typedef struct s_player			t_player;
typedef struct s_ray_info		t_ray_info;
typedef struct s_map			t_map;
typedef struct s_minirect		t_minirect;
typedef struct s_miniline		t_miniline;
typedef enum e_direction		t_direction;
typedef struct s_data			t_data;
typedef struct s_wall_render	t_wall_render;

enum e_background
{
	CEIL,
	ROOF,
};

enum e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

struct s_key
{
	int	w;
	int	d;
	int	s;
	int	q;
	int	left;
	int	right;
};

struct s_ray_info
{
	t_direction	direction;
	double		length;
	double		hit_x;
	double		hit_y;
	double		angle;
};

struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_mlx
{
	void	*server;
	void	*window;
	t_pixel	*pixel;
};

struct s_map
{
	int		width;
	int		height;
	char	**data;
};

struct s_config
{
	void			*textures[4];
	t_map			*map;
	unsigned int	ceil;
	unsigned int	floor;
};

struct s_player
{
	int		x;
	int		y;
	double	angle;
	double	delta_x;
	double	delta_y;
};


struct s_cub3d
{
	t_mlx		*mlx;
	t_config	*config;
	t_key		*key;
	t_player	*player;
	t_ray_info	*ray;
	int			refresh;
};

struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		f;
	int		c;
	char	**map;
};

struct s_miniline
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	color;
};

struct s_minirect
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	bg_color;
};

struct s_wall_render
{
	double	correct_distance;
	double	line_height;
	int		line0;
	double	tex_step;
	double	tex_offset;
	double	tex_y;
	double	tex_x;
};

void		cube_init(t_cub3d *cube);
t_mlx		*mlx_alloc(t_cub3d *cube);
t_config	*config_alloc(t_cub3d *cube, t_data *data);
t_map		*map_alloc(int width, int height);
t_map		*map_clone(t_map *map);
t_key		*key_alloc(t_cub3d *cube);
t_player	*player_alloc(t_cub3d *cube, int x, int y, double angle);
void		map_free(t_map *map);
void		mlx_free(t_mlx *mlx);
void		config_free(t_config *config, void *mlx);
void		key_free(t_key *key);
void		player_free(t_player *player);
void		rayinfo_free(t_ray_info *ray);
void		cube_destroy(t_cub3d *cube);
void		fatal_error(t_cub3d *cube, char *msg, int code);

void		put_pixel_at(t_cub3d *game, int x, int y, int color);
#endif