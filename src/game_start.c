/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:58:47 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 17:55:42 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_start(t_game *g)
{
	int	i;
	int	j;

	ft_printf(">>Entered game_start.\n");
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->width * 34,
			g->height * 34 + 20, "so_long");
	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (g->map[i][j])
		{
			insert(g, i, j);
			g->coordi.x += 34;
			j++;
		}
		g->coordi.y += 34;
		i++;
	}
	ft_printf(">>Exit game_start.\n");
}

void	insert(t_game *g, int x, int y)
{
	if (g->map[x][y] == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->textures.lava_img, g->coordi.x, g->coordi.y);
	if (g->map[x][y] == '0')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->textures.grass_img, g->coordi.x, g->coordi.y);
	if (g->map[x][y] == 'P')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->textures.b_fr_one_img, g->coordi.x, g->coordi.y);
	if (g->map[x][y] == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->textures.coll_img, g->coordi.x, g->coordi.y);
	if (g->map[x][y] == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
				g->textures.cellar_img, g->coordi.x, g->coordi.y);
}
