/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 07:10:44 by erijania          #+#    #+#             */
/*   Updated: 2025/03/08 08:31:16 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	fatal_error(t_cube3d *cube, char *msg, int code)
{
	cube_destroy(cube);
	ft_putstr_fd(msg, 2);
	exit(code);
}
