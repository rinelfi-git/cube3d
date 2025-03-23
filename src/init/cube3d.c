/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:47:22 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 16:44:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	cube_init(t_cub3d *cube)
{
	cube->config = NULL;
	cube->key = NULL;
	cube->mlx = NULL;
	cube->player = NULL;
	cube->ray = NULL;
	cube->refresh = 1;
}

void	cube_destroy(t_cub3d *cube)
{
	if (cube->config)
		config_free(&(cube->config), cube->mlx->server);
	if (cube->key)
		key_free(&(cube->key));
	if (cube->player)
		player_free(&(cube->player));
	if (cube->ray)
		rayinfo_free(&(cube->ray));
	if (cube->mlx)
		mlx_free(&(cube->mlx));
}
