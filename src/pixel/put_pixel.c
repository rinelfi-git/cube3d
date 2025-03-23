/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:21:27 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 22:33:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_at(t_cub3d *game, int x, int y, int color)
{
	char	*addr;
	t_pixel	*pix;
	
	pix = &(game->mlx->pixel);
	addr = pix->addr + (y * pix->line_length + x * (pix->bits_per_pixel / 8));
	*((unsigned int *) addr) = color;
}
