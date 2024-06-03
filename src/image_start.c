/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:40:49 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/07 15:23:58 by cadenegr         ###   ########.fr       */
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

void	free_images(t_game *g)
{
	ft_printf("Enter free_images!\n");
	if (g->textures.grass_img != NULL)
	{
		ft_printf("Enter free_images!\n");
		mlx_destroy_image(g->mlx_ptr, g->textures.grass_img);
	}
	mlx_destroy_image(g->mlx_ptr, g->textures.coll_img);
	mlx_destroy_image(g->mlx_ptr, g->textures.cellar_img);
	mlx_destroy_image(g->mlx_ptr, g->textures.lava_img);
	mlx_destroy_image(g->mlx_ptr, g->textures.b_fr_one_img);
	ft_printf("Enter free_images3!\n");
	ft_free(g);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	mlx_destroy_display(g->mlx_ptr);
	free(g->mlx_ptr);
	ft_printf("Exit free_images!\n");
}
