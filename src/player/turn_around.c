/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:22:08 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 22:23:45 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player *player)
{
	player->angle -= TURN_STEP;
	if (player->angle < 0)
		player->angle += PI * 2;
}

void	turn_right(t_player *player)
{
	player->angle += TURN_STEP;
	if (player->angle > PI * 2)
		player->angle -= PI * 2;
}
