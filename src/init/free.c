/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:22:06 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:24:35 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	if (map->data)
	{
		while (map->data[i])
			free(map->data[i++]);
		free(map->data);
	}
	free(map);
}
