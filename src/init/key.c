/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:35:40 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 16:44:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

t_key	*key_alloc(t_cub3d *cube)
{
	t_key	*out;

	out = malloc(sizeof(t_key));
	if (!out)
		fatal_error(cube, MALLOC_ERROR, 1);
	out->w = 0;
	out->d = 0;
	out->s = 0;
	out->q = 0;
	out->left = 0;
	out->right = 0;
	return (out);
}

void	key_free(t_key *key)
{
	free(key);
}
