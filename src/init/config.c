/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:49:14 by erijania          #+#    #+#             */
/*   Updated: 2025/03/10 05:27:43 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	load_configs(t_config *config, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	// loop get textures
	config->textures[NORTH] = NULL;
	// loop get floor and ceil color
	// loop to get map;
	close(fd);
}

t_config	*config_alloc(t_cube3d *cube, char *path)
{
	t_config	*out;

	out = malloc(sizeof(t_config));
	if (!out)
		fatal_error(cube, MALLOC_ERROR, 1);
	out->colors[0] = 0x000000;
	out->colors[1] = 0x000000;
	out->map = NULL;
	out->textures[NORTH] = NULL;
	out->textures[EAST] = NULL;
	out->textures[SOUTH] = NULL;
	out->textures[WEST] = NULL;
	load_configs(out, path);
	return (out);
}

void	config_free(t_config *config, void *mlx)
{
	int	i;

	if (config->map)
	{
		i = 0;
		while (config->map[i])
			free(config->map[i++]);
		free(config->map);
	}
	i = 0;
	while (i < 4)
	{
		if (config->textures[i])
			mlx_destroy_image(mlx, config->textures[i++]);
	}
}
