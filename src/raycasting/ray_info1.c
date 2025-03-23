/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_info1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:10:37 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:15:23 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <math.h>

void	init_ray_variables(t_cub3d *cub, double angle, t_ray_vars *var)
{
	var->ray_x = cub->player->x;
	var->ray_y = cub->player->y;
	var->map_x = (int)(var->ray_x / BLOCK_SIZE);
	var->map_y = (int)(var->ray_y / BLOCK_SIZE);
	var->dx = -cos(angle);
	var->dy = -sin(angle);
	var->d_dist_x = fabs(1.0 / var->dx);
	var->d_dist_y = fabs(1.0 / var->dy);
	var->step_x = var->dx < 0 ? -1 : 1;
	var->step_y = var->dy < 0 ? -1 : 1;
	if (var->dx < 0)
		var->next_delta_x = (var->ray_x - var->map_x * BLOCK_SIZE)
			/ fabs(var->dx);
	else
		var->next_delta_x = ((var->map_x + 1) * BLOCK_SIZE - var->ray_x)
			/ fabs(var->dx);
	if (var->dy < 0)
		var->next_delta_y = (var->ray_y - var->map_y * BLOCK_SIZE)
			/ fabs(var->dy);
	else
		var->next_delta_y = ((var->map_y + 1) * BLOCK_SIZE - var->ray_y)
			/ fabs(var->dy);
}

static void	update_vertical(t_ray_vars *var, t_direction *dir)
{
	var->ray_x += var->next_delta_y * var->dx;
	var->ray_y += var->next_delta_y * var->dy;
	var->next_delta_x -= var->next_delta_y;
	var->next_delta_y = var->d_dist_y * BLOCK_SIZE;
	var->map_y += var->step_y;
	*(dir) = var->step_y < 0 ? NORTH : SOUTH;
}

static void	update_horizontal(t_ray_vars *var, t_direction *dir)
{
	var->ray_x += var->next_delta_x * var->dx;
	var->ray_y += var->next_delta_x * var->dy;
	var->next_delta_y -= var->next_delta_x;
	var->next_delta_x = var->d_dist_x * BLOCK_SIZE;
	var->map_x += var->step_x;
	*(dir) = var->step_x < 0 ? WEST : EAST;
}

int	step_ray_loop(t_cub3d *game, t_ray_vars *var, t_ray_info *r)
{
	t_map	*map;

	map = game->config->map;
	if (var->next_delta_x < var->next_delta_y)
		update_horizontal(var, &(r->direction));
	else
		update_vertical(var, &(r->direction));
	if (var->map_y < 0 || var->map_y > map->height || var->map_x < 0
		|| var->map_x >= map->width)
	{
		r->length = map->height * map->width * BLOCK_SIZE;
		return (1);
	}
	if (map->data[var->map_y][var->map_x] == '1')
	{
		r->hit_x = var->ray_x;
		r->hit_y = var->ray_y;
		r->length = sqrt(pow(var->ray_x - game->player->x, 2) + pow(var->ray_y
					- game->player->y, 2));
		return (1);
	}
	return (0);
}
