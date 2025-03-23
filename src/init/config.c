/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:49:14 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:07:22 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

t_config	*config_alloc(t_cub3d *game, t_data *data)
{
	t_config	*out;

	out = malloc(sizeof(t_config));
	if (!out)
		fatal_error(game, MALLOC_ERROR, 1);
	out->ceil = data->c;
	out->floor = data->f;
	out->map = map_from_array(data->map);
	out->textures[NORTH] = mlx_xpm_file_to_image(game->mlx->server, data->north,
			NULL, NULL);
	out->textures[SOUTH] = mlx_xpm_file_to_image(game->mlx->server, data->south,
			NULL, NULL);
	out->textures[EAST] = mlx_xpm_file_to_image(game->mlx->server, data->east,
			NULL, NULL);
	out->textures[WEST] = mlx_xpm_file_to_image(game->mlx->server, data->west,
			NULL, NULL);
	return (out);
}

void	config_free(t_config *config, void *mlx)
{
	int	i;

	if (config->map)
		map_free(config->map);
	i = 0;
	while (i < 4)
	{
		if (config->textures[i])
			mlx_destroy_image(mlx, config->textures[i++]);
	}
}
