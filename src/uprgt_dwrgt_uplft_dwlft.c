/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uprgt_dwrgt_uplft_dwlft.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:11 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 14:59:18 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_right(t_game *g)
{
	ft_printf("Enter move_up_right.\n");
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y - 1] == '1')
		return ;
	else
	{
		g->coordi.old_px = g->coordi.p_x;
		g->coordi.old_py = g->coordi.p_y;
	}
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y - 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y - 1] == 'E'
		&& g->c == g->total_collect)
	{
		g->map[g->coordi.p_x + 1][g->coordi.p_y - 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
		finish(g);
	}
	else
	{
		g->map[g->coordi.p_x + 1][g->coordi.p_y - 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
	}
	ft_printf("Exit move_up_right.\n");
}

void	move_down_left(t_game *g)
{
	ft_printf("Enter move_down_left.\n");
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y + 1] == '1')
		return ;
	else
	{
		g->coordi.old_px = g->coordi.p_x;
		g->coordi.old_py = g->coordi.p_y;
	}
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y + 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y + 1] == 'E'
		&& g->c == g->total_collect)
	{
		g->map[g->coordi.p_x - 1][g->coordi.p_y + 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
		finish(g);
	}
	else
	{
		g->map[g->coordi.p_x - 1][g->coordi.p_y + 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
	}
	ft_printf("Exit move_down_left.\n");
}

void	move_down_right(t_game *g)
{
	ft_printf("Enter move_down_right.\n");
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y + 1] == '1')
		return ;
	else
	{
		g->coordi.old_px = g->coordi.p_x;
		g->coordi.old_py = g->coordi.p_y;
	}
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y + 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x + 1][g->coordi.p_y + 1] == 'E'
		&& g->c == g->total_collect)
	{
		g->map[g->coordi.p_x + 1][g->coordi.p_y + 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
		finish(g);
	}
	else
	{
		g->map[g->coordi.p_x + 1][g->coordi.p_y + 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
	}
	ft_printf("Exit move_down_right.\n");
}

void	move_up_left(t_game *g)
{
	ft_printf("Enter move_up_left.\n");
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y - 1] == '1')
		return ;
	else
	{
		g->coordi.old_px = g->coordi.p_x;
		g->coordi.old_py = g->coordi.p_y;
	}
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y - 1] == 'C')
		g->c++;
	if (g->map[g->coordi.p_x - 1][g->coordi.p_y - 1] == 'E'
		&& g->c == g->total_collect)
	{
		g->map[g->coordi.p_x - 1][g->coordi.p_y - 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
		finish(g);
	}
	else
	{
		g->map[g->coordi.p_x - 1][g->coordi.p_y - 1] = 'P';
		g->map[g->coordi.old_px][g->coordi.old_py] = '0';
		g->moves++;
	}
	ft_printf("Exit move_up_left.\n");
}
