/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 05:54:58 by erijania          #+#    #+#             */
/*   Updated: 2025/03/08 06:18:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define W_HEIGHT 480
# define W_WIDTH 640
# define BLOCK_SIZE
# define TEXTURE_SIZE
# define MOVE_STEP
# define TURN_STEP
# define PI 3.141592653589793
# define FOV PI / 3.0
# define MALLOC_ERROR "Memory allocation error"
# define XSERVER_ERROR "Cannot start xlib server"
# include "mlx.h"

typedef struct s_cube3d		t_cube3d;
typedef struct s_mlx		t_mlx;
typedef struct s_config		t_config;
typedef struct s_pixel		t_pixel;
typedef struct s_key		t_key;
typedef struct s_player		t_player;
typedef struct s_ray_info	t_ray_info;
typedef enum e_direction	t_direction;

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

struct s_config
{
	void			*textures[4];
	char			**map;
	unsigned int	colors[2];
};

struct s_player
{
	int		x;
	int		y;
	double	angle;
	double	delta_x;
	double	delta_y;
};


struct s_cube3d
{
	t_mlx		*mlx;
	t_config	*config;
	t_key		*key;
	t_player	*player;
	t_ray_info	*ray;
	int			refresh;
};

void		cube_init(t_cube3d *cube);
t_mlx		*mlx_alloc(t_cube3d *cube);
t_config	*config_alloc(t_cube3d *cube, char *path);
t_key		*key_alloc(t_cube3d *cube);
t_player	*player_alloc(t_cube3d *cube, int x, int y, double angle);
void		mlx_free(t_mlx *mlx);
void		config_free(t_config *config, void *mlx);
void		key_free(t_key *key);
void		player_free(t_player *player);
void		rayinfo_free(t_ray_info *ray);
void		cube_destroy(t_cube3d *cube);
void		fatal_error(t_cube3d *cube, char *msg, int code);
#endif