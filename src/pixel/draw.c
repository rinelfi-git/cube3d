/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:15:19 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 22:39:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	draw_rectangle(t_cub3d *game, t_minirect *form)
{
	int	i;
	int	j;

	j = form->y;
	while (j < (form->y + form->height))
	{
		i = form->x;
		while (i < (form->x + form->width))
			put_pixel_at(game, i++, j, form->bg_color);
		j++;
	}
}

void	draw_square(t_cub3d *game, int x, int y, int size, int out, int bg)
{
	int	i;
	int	j;

	j = y;
	while (j <= y + size)
	{
		i = x;
		while (i <= x + size)
			if (i == x || j == y)
				put_pixel_at(game, i++, j, out);
			else
				put_pixel_at(game, i++, j, bg);
		j++;
	}
}

void	draw_line(t_cub3d *prog, t_miniline *line)
{
	float	deltas[2];
	float	pixels[2];
	int		pixel;

	if (line->start_x == line->end_x && line->start_y == line->end_y)
		return ;
	deltas[0] = line->end_x - line->start_x;
	deltas[1] = line->end_y - line->start_y;
	pixel = sqrtf((deltas[0] * deltas[0]) + (deltas[1] * deltas[1]));
	deltas[0] /= pixel;
	deltas[1] /= pixel;
	pixels[0] = line->start_x;
	pixels[1] = line->start_y;
	while (pixel)
	{
		put_pixel_at(prog, pixels[0], pixels[1], line->color);
		pixels[0] += deltas[0];
		pixels[1] += deltas[1];
		--pixel;
	}
}

void	draw_background(t_cub3d *game)
{
	t_minirect	ceil;
	t_minirect	floor;
	
	ceil.x = 0;
	ceil.y = 0;
	ceil.width = W_WIDTH;
	ceil.height = W_HEIGHT;
	ceil.bg_color = game->config->ceil;
	draw_rectangle(game, &ceil);
	floor.x = 0;
	floor.y = W_HEIGHT / 2;
	floor.width = W_WIDTH;
	floor.height = W_HEIGHT - floor.y;
	floor.bg_color = game->config->floor;
	draw_rectangle(game, &floor);
}
