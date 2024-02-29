/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:40:49 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 18:01:34 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_img(t_game *g)
{
	ft_printf("Enter start_img.\n");
	g->textures.grass_img = mlx_xpm_file_to_image(g->mlx_ptr,
		GRASS, &g->coordi.x, &g->coordi.y);
	g->textures.lava_img = mlx_xpm_file_to_image(g->mlx_ptr,
		LAVA, &g->coordi.x, &g->coordi.y);
	g->textures.b_fr_one_img = mlx_xpm_file_to_image(g->mlx_ptr,
		B_FR_ONE, &g->coordi.x, &g->coordi.y);
	g->textures.cellar_img = mlx_xpm_file_to_image(g->mlx_ptr,
		CELLAR, &g->coordi.x, &g->coordi.y);
	g->textures.coll_img = mlx_xpm_file_to_image(g->mlx_ptr,
		COLLECTABILE, &g->coordi.x, &g->coordi.y);
	ft_printf("Exit start_img.\n");
}

