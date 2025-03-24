/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:47:22 by erijania          #+#    #+#             */
/*   Updated: 2025/03/24 09:36:27 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	cube_init(t_cub3d *game)
{
	game->mlx = mlx_alloc();
	if (!game->mlx)
		fatal_error(game, MALLOC_ERROR, 1);
	game->config = NULL;
	game->key = key_alloc(game);
	game->player = player_alloc(game, 12, 12, PI / 2);
	game->ray = NULL;
	game->refresh = 1;
}

int	cube_destroy(t_cub3d *cube)
{
	if (cube->config)
		config_free(cube->config, cube->mlx->server);
	if (cube->key)
		key_free(cube->key);
	if (cube->player)
		player_free(cube->player);
	if (cube->ray)
		rayinfo_free(cube->ray);
	if (cube->mlx)
		mlx_free(cube->mlx);
	return (0);
}
