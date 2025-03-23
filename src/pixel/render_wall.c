/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:43:22 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:14:55 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	prepare_wall_render(t_cub3d *game, t_ray_info *info,
		t_wall_render *r)
{
	r->correct_distance = info->length * cos(game->player->angle - info->angle);
	r->line_height = BLOCK_SIZE * W_HEIGHT / r->correct_distance;
	r->tex_offset = 0;
	r->tex_step = TEXTURE_SIZE / r->line_height;
	if (r->line_height > W_HEIGHT)
	{
		r->tex_offset = (r->line_height - W_HEIGHT) / 2;
		r->line_height = W_HEIGHT;
	}
	r->line0 = (int)(W_HEIGHT / 2.0 - r->line_height / 2.0);
	r->tex_y = r->tex_offset * r->tex_step;
	if (info->direction == NORTH || info->direction == SOUTH)
	{
		r->tex_x = (int)(info->hit_x / (BLOCK_SIZE / TEXTURE_SIZE))
			% TEXTURE_SIZE;
		if (info->angle > PI)
			r->tex_x = TEXTURE_SIZE - 1 - r->tex_x;
	}
	else
	{
		r->tex_x = (int)(info->hit_y / (BLOCK_SIZE / TEXTURE_SIZE))
			% TEXTURE_SIZE;
		if (info->angle < (PI / 2) || info->angle > (3 * PI / 2))
			r->tex_x = TEXTURE_SIZE - 1 - r->tex_x;
	}
}

void	draw_wall(t_cub3d *game, int ray, t_ray_info *info)
{
	t_wall_render	r;
	int				y;

	prepare_wall_render(game, info, &r);
	y = 0;
	while (y < (int)r.line_height)
	{
		put_pixel_at(game, ray, y + r.line0,
			get_texture_color(game->config->textures[info->direction],
				(int)r.tex_x, (int)r.tex_y));
		y++;
		r.tex_y += r.tex_step;
	}
}
