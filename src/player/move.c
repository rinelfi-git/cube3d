/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:14:21 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 22:21:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward(t_player *player)
{
	player->x -= roundf(player->delta_x * MOVE_STEP);
	player->y -= roundf(player->delta_y * MOVE_STEP);
}

void	move_backward(t_player *player)
{
	player->x += roundf(player->delta_x * MOVE_STEP);
	player->y += roundf(player->delta_y * MOVE_STEP);
}

void	move_left(t_player *player)
{
	player->x -= roundf(player->delta_x * MOVE_STEP);
	player->y += roundf(player->delta_y * MOVE_STEP);
}

void	move_right(t_player *player)
{
	player->x += roundf(player->delta_x * MOVE_STEP);
	player->y -= roundf(player->delta_y * MOVE_STEP);
}
