/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:00:19 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 23:21:01 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

static void	free_2darray(char **array, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
		free(array[i++]);
	free(array);
}

static int	create_map(t_map *map)
{
	int		i;
	
	map->data = malloc(sizeof(char *) * (map->height + 1));
	if (!map->data)
	{
		free(map);
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		map->data[i] = malloc(sizeof(char) * (map->width + 1));
		ft_memset(map->data[i], '1', map->width + 1);
		if (!map->data[i++])
		{
			free_2darray(map->data, i);
			free(map);
			return (0);
		}
	}
	map->data[i] = NULL;
	return (1);
}

t_map	*map_alloc(int width, int height)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	if (!out)
		return (NULL);
	out->width = width;
	out->height = height;
	if (!create_map(out))
		return (NULL);
	return (out);
}

static void	fill_data(t_map *map, char **data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = -1;
		while (data[i][++j])
		{
			if (ft_strchr("10NEWS", data[i][j]))
				map->data[i][j] = data[i][j];
		}
		i++;
	}
}

t_map	*map_from_array(char **data)
{
	t_map	*out;
	int		height;
	int		width;

	height = 0;
	width = 0;
	while(data[height])
		width = imax(width, ft_strlen(data[height++]));
	out = map_alloc(width, height);
	if (!out)
		return (NULL);
	fill_data(out, data);
	return (out);
}
