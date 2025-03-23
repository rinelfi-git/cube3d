/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:50:55 by erijania          #+#    #+#             */
/*   Updated: 2025/03/23 21:59:18 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	init_ray_variables(t_cub3d *cub, double angle, t_ray_vars *var);
int		step_ray_loop(t_cub3d *game, t_ray_vars *var, t_ray_info *r);

void	calculate_ray_hit(t_cub3d *cub, t_ray_vars *v, t_ray_info *r)
{
	while (1)
	{
		if (step_ray_loop(cub, v, r))
			break ;
	}
}

t_ray_info	*get_ray_info(t_cub3d *cub, double angle)
{
	t_ray_info	*info;
	t_ray_vars	vars;

	info = malloc(sizeof(t_ray_info));
	if (!info)
		return (NULL);
	info->angle = angle;
	info->length = 0;
	info->hit_x = 0;
	info->hit_y = 0;
	init_ray_variables(cub, angle, &vars);
	calculate_ray_hit(cub, &vars, info);
	return (info);
}
