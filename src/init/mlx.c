/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:51:20 by erijania          #+#    #+#             */
/*   Updated: 2025/03/10 05:32:26 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include <stdlib.h>

static t_pixel	*pixel_alloc(t_cube3d *cube)
{
	t_pixel	*out;

	out = malloc(sizeof(t_pixel));
	if (!out)
		fatal_error(cube, MALLOC_ERROR, 1);
	out->img = mlx_new_image(cube->mlx->server, W_WIDTH, W_HEIGHT);
	out->addr = mlx_get_data_addr(out->img, &(out->bits_per_pixel), &(out->line_length), &(out->endian));
	return (out);
}

static void	pixel_free(t_pixel *pixel, void *mlx)
{
	mlx_destroy_image(mlx, pixel->img);
	free(pixel);
}

t_mlx	*mlx_alloc(t_cube3d *cube)
{
	t_mlx	*out;
	void	*mlx;

	out = malloc(sizeof(t_mlx));
	if (!out)
		fatal_error(cube, MALLOC_ERROR, 1);
	mlx = mlx_init();
	out->server = mlx;
	out->window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Cube3D");
	out->pixel = pixel_alloc(cube);
	return (out);
}

void	mlx_free(t_mlx *mlx)
{
	if (mlx->pixel)
		pixel_free(mlx->pixel, mlx->server);
	if (mlx->window)
		mlx_destroy_display(mlx->window);
	
}
