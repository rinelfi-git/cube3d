/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:00:19 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 19:19:20 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static void	free_2darray(void **array, int size)
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
		ft_bzero(map->data[i], map->width + 1);
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

t_map	*map_clone(t_map *map)
{
	t_map	*out;
	int		i;

	out = map_alloc(map->width, map->height);
	if (!out)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		ft_strlcpy(out->data[i], map->data[i], map->width);
		i++;
	}
	return (out);
}
