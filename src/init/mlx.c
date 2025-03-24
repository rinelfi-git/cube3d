/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:51:20 by erijania          #+#    #+#             */
/*   Updated: 2025/03/24 09:37:11 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static t_pixel	*pixel_alloc(t_mlx *mlx)
{
	t_pixel	*out;

	out = malloc(sizeof(t_pixel));
	if (!out)
		return (NULL);
	out->img = mlx_new_image(mlx->server, W_WIDTH, W_HEIGHT);
	out->addr = mlx_get_data_addr(out->img, &(out->bits_per_pixel),
			&(out->line_length), &(out->endian));
	return (out);
}

static void	pixel_free(t_pixel *pixel, void *mlx)
{
	mlx_destroy_image(mlx, pixel->img);
	free(pixel);
}

t_mlx	*mlx_alloc()
{
	t_mlx	*out;
	void	*mlx;

	out = malloc(sizeof(t_mlx));
	if (!out)
		return (NULL);
	mlx = mlx_init();
	if (!mlx)
		return (NULL);
	out->server = mlx;
	out->window = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Cube3D");
	out->pixel = pixel_alloc(out);
	if (!out->pixel)
		return (NULL);
	return (out);
}

void	mlx_free(t_mlx *mlx)
{
	if (mlx->pixel)
		pixel_free(mlx->pixel, mlx->server);
	if (mlx->window)
		mlx_destroy_display(mlx->window);
}
