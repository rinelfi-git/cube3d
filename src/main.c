/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:46:18 by erijania          #+#    #+#             */
/*   Updated: 2025/03/24 09:38:25 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <X11/keysym.h>

static int	gameloop(void *arg)
{
	t_cub3d	*game;

	game = (t_cub3d *)arg;
	if (!game->refresh)
		return (0);
	if (game->key->w && check_collision(game, 'z'))
		move_forward(game->player);
	else if (game->key->s && check_collision(game, 's'))
		move_backward(game->player);
	else if (game->key->a && check_collision(game, 'q'))
		move_left(game->player);
	else if (game->key->d && check_collision(game, 'd'))
		move_right(game->player);
	if (game->key->left)
		turn_left(game->player);
	else if (game->key->right)
		turn_right(game->player);
	game->player->delta_x = cosf(game->player->angle);
	game->player->delta_y = sinf(game->player->angle);
	draw_background(game);
	draw_3d(game);
	mlx_put_image_to_window(game->mlx->server,
			game->mlx->window, game->mlx->pixel->img, 0, 0);
	return (0);
}

int	need_refresh(t_cub3d *game)
{
	return (game->key->w || game->key->d || game->key->s
		|| game->key->a || game->key->left
		|| game->key->right);
}

static int	handle_keyup(int code, void *arg)
{
	t_cub3d	*game;

	game = (t_cub3d *)arg;
	if (code == XK_z)
		game->key->w = 0;
	if (code == XK_d)
		game->key->d = 0;
	if (code == XK_s)
		game->key->s = 0;
	if (code == XK_q)
		game->key->a = 0;
	if (code == XK_Left)
		game->key->left = 0;
	if (code == XK_Right)
		game->key->left = 0;
	game->refresh = need_refresh(game);
	return (0);
}

static int	handle_keydown(int code, void *arg)
{
	t_cub3d	*game;

	game = (t_cub3d *)arg;
	if (code == XK_z)
		game->key->w = 1;
	if (code == XK_d)
		game->key->d = 1;
	if (code == XK_s)
		game->key->s = 1;
	if (code == XK_q)
		game->key->a = 1;
	if (code == XK_Left)
		game->key->left = 1;
	if (code == XK_Right)
		game->key->right = 1;
	if (code == XK_Escape)
		return (cube_destroy(game));
	game->refresh = need_refresh(game);
	return (0);
}

int	main(void)
{
	t_cub3d	game;

	cube_init(&game);
	mlx_hook(game.mlx->window, 3, 1L << 1, handle_keyup, &game);
	mlx_hook(game.mlx->window, 2, 1L << 0, handle_keydown, &game);
	mlx_hook(game.mlx->window, 17, 0L, cube_destroy, &game);
	mlx_loop_hook(game.mlx->server, gameloop, &game);
	cube_destroy(&game);
	return (0);
}
