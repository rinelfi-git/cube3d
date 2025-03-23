/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 06:02:51 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:15:40 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	draw_3d(t_cub3d *game)
{
	int			ray;
	float		angle_step;
	float		ray_angle;
	float		start_angle;
	t_ray_info	*ray_info;

	ray = 0;
	angle_step = FOV / W_WIDTH;
	start_angle = game->player->angle - FOV / 2.0;
	while (ray <= W_WIDTH)
	{
		ray_angle = start_angle + (ray * angle_step);
		ray_info = get_ray_info(game, ray_angle);
		draw_wall(game, ray, ray_info);
		free(ray_info);
		ray++;
	}
}
