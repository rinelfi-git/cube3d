/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:51:49 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 16:44:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <math.h>

t_player	*player_alloc(t_cub3d *cube, int x, int y, double angle)
{
	t_player	*out;

	out = malloc(sizeof(t_player));
	if (!out)
		fatal_error(cube, MALLOC_ERROR, 1);
	out->x = x;
	out->y = y;
	out->angle = angle;
	out->delta_x = cos(angle);
	out->delta_y = sin(angle);
	return (out);
}

void	player_free(t_player *player)
{
	free(player);
}
