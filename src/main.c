/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erijania <erijania@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:46:18 by erijania          #+#    #+#             */
/*   Updated: 2025/03/22 22:28:21 by erijania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_cub3d	game;
	
	(void)argc;
	(void *)argv;
	cube_init(&game);
	cube_destroy(&game);
	return (0);
}
