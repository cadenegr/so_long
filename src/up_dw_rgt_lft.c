/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_dw_rgt_lft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:36:35 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/07 14:59:27 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *g)
{
	ft_printf("Enter move_up.\n");
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y] == '1')
		return ;
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y] != 'E')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, g->coordi.p_y * 34, (g->coordi.p_x - 1) * 34);
	}
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y] == 'E'
		&& g->c == g->total_collect)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, g->coordi.p_y * 34, (g->coordi.p_x - 1) * 34);
		g->moves++;
		finish(g);
	}
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y] == 'E'
		&& g->c != g->total_collect)
		return ;
	g->moves++;
	g->map[g->coordi.p_x - 1][g->coordi.p_y] = 'P';
	g->map[g->coordi.p_x][g->coordi.p_y] = '0';
	g->coordi.p_x -= 1;
	ft_printf("Exit move_up.\n");
}

void	move_down(t_game *g)
{
	ft_printf("Enter move_down.\n");
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y] == '1')
		return ;
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y] != 'E')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, g->coordi.p_y * 34, (g->coordi.p_x + 1) * 34);
	}
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y] == 'E'
		&& g->c == g->total_collect)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, g->coordi.p_y * 34, (g->coordi.p_x + 1) * 34);
		g->moves++;
		finish(g);
	}
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y] == 'E'
		&& g->c != g->total_collect)
		return ;
	g->moves++;
	g->map[g->coordi.p_x + 1][g->coordi.p_y] = 'P';
	g->map[g->coordi.p_x][g->coordi.p_y] = '0';
	g->coordi.p_x += 1;
	ft_printf("Exit move_down.\n");
}

void	move_right(t_game *g)
{
	ft_printf("Enter right.\n");
	if (g->map[g->coordi.p_x][g->coordi.p_y + 1] == '1')
		return ;
	if (g->map[g->coordi.p_x][g->coordi.p_y + 1] != 'E')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, (g->coordi.p_y + 1) * 34, g->coordi.p_x * 34);
	}
	if (g->map[g->coordi.p_x][g->coordi.p_y + 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x][g->coordi.p_y + 1] == 'E'
		&& g->c == g->total_collect)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, (g->coordi.p_y + 1) * 34, g->coordi.p_x * 34);
		g->moves++;
		finish(g);
	}
	if (g->map[g->coordi.p_x][g->coordi.p_y + 1] == 'E'
		&& g->c != g->total_collect)
		return ;
	g->moves++;
	g->map[g->coordi.p_x][g->coordi.p_y + 1] = 'P';
	g->map[g->coordi.p_x][g->coordi.p_y] = '0';
	g->coordi.p_y += 1;
	ft_printf("Exit right.\n");
}

void	move_left(t_game *g)
{
	ft_printf("Enter move_up.\n");
	if (g->map[g->coordi.p_x][g->coordi.p_y - 1] == '1')
		return ;
	if (g->map[g->coordi.p_x][g->coordi.p_y - 1] != 'E')
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, (g->coordi.p_y - 1) * 34, (g->coordi.p_x) * 34);
	}
	if (g->map[g->coordi.p_x][g->coordi.p_y - 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x][g->coordi.p_y - 1] == 'E'
		&& g->c == g->total_collect)
	{
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.grass_img, g->coordi.p_y * 34, g->coordi.p_x * 34);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
			g->textures.b_fr_one_img, (g->coordi.p_y - 1) * 34, (g->coordi.p_x) * 34);
		g->moves++;
		finish(g);
	}
	if (g->map[g->coordi.p_x][g->coordi.p_y - 1] == 'E'
		&& g->c != g->total_collect)
		return ;
	g->moves++;
	g->map[g->coordi.p_x][g->coordi.p_y - 1] = 'P';
	g->map[g->coordi.p_x][g->coordi.p_y] = '0';
	g->coordi.p_y -= 1;
	ft_printf("Exit move_up.\n");
}
