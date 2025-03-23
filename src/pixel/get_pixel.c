/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:13:06 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:14:25 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	get_texture_color(void *texture, int x, int y)
{
	int		bit;
	int		length;
	int		endian;
	char	*address;

	address = mlx_get_data_addr(texture, &bit, &length, &endian);
	return (*(unsigned int *)(address + (y * length + x * (bit / 8))));
}
