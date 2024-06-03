/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:02:52 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/07 11:20:03 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *g, int key)
{
	ft_printf(">>>Enter movement.\n");
	if (key == KEY_W)
		move_up(g);
	if (key == 9)
		move_up_right(g);
	if (key == KEY_D)
		move_right(g);
	if (key == 3)
		move_down_right(g);
	if (key == KEY_S)
		move_down(g);
	if (key == 1)
		move_down_left(g);
	if (key == KEY_A)
		move_left(g);
	if (key == 7)
		move_up_left(g);
	ft_printf(">>>Exit movement.\n");
}


