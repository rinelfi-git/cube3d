/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:03:36 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:15:10 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	check_move_forward(int *mx, int *my, t_player *player)
{
	double	dx;
	double	dy;

	dx = player->delta_x * MOVE_STEP * 5;
	dy = player->delta_y * MOVE_STEP * 5;
	*(my) = roundf(player->y - dy);
	*(mx) = roundf(player->x - dx);
}

static void	check_move_backward(int *mx, int *my, t_player *player)
{
	double	dx;
	double	dy;

	dx = player->delta_x * MOVE_STEP * 5;
	dy = player->delta_y * MOVE_STEP * 5;
	*(my) = roundf(player->y + dy);
	*(mx) = roundf(player->x + dx);
}

static void	check_move_left(int *mx, int *my, t_player *player)
{
	double	dx;
	double	dy;

	dx = player->delta_x * MOVE_STEP * 5;
	dy = player->delta_y * MOVE_STEP * 5;
	*(my) = roundf(player->y - dy);
	*(mx) = roundf(player->x + dx);
}

static void	check_move_right(int *mx, int *my, t_player *player)
{
	double	dx;
	double	dy;

	dx = player->delta_x * MOVE_STEP * 5;
	dy = player->delta_y * MOVE_STEP * 5;
	*(my) = roundf(player->y + dy);
	*(mx) = roundf(player->x - dx);
}

int	check_collision(t_cub3d *game, char key)
{
	int 	map_x;
	int		map_y;
	t_map	*map;

	map_x = -1;
	map_y = -1;
	map = game->config->map;
	if (key == 'w')
		check_move_forward(&map_x, &map_y, game->player);
	else if (key == 's')
		check_move_backward(&map_x, &map_y, game->player);
	else if (key == 'a')
		check_move_left(&map_x, &map_y, game->player);
	else if (key == 'd')
		check_move_right(&map_x, &map_y, game->player);
	if (map_x >= 0 && map_y >= 0)
		return (map->data[map_y / BLOCK_SIZE][map_x / BLOCK_SIZE] == '1');
	return (1);
}
