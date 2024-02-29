/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:24:06 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 17:47:19 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_game *g)
{
	ft_printf(">>Enter ft struct_init.\n");
	g->height = 0;
	g->width = 0;
	g->previous_width = 0;
	g->fd = 0;
	g->p = 0;
	g->c = 0;
	g->e = 0;
	g->map = NULL;
	g->temp_map = NULL;
	g->coordi.p_x = 0;
	g->coordi.p_y = 0;
	g->coordi.old_px = 0;
	g->coordi.old_py = 0;
	g->coordi.x = 0;
	g->coordi.y = 0;
	g->moves = 0;
	g->total_collect = 0;
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->textures.b_fr_one_img = NULL;
	g->textures.grass_img = NULL;
	g->textures.lava_img = NULL;
	g->textures.cellar_img = NULL;
	g->textures.coll_img = NULL;
	ft_printf(">>Exit ft struct_init.\n");
}