/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:02:52 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 14:48:38 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *g, int key)
{
	if (key == 8)
		move_up(g);
	if (key == 9)
		move_up_right(g);
	if (key == 6)
		move_right(g);
	if (key == 3)
		move_down_right(g);
	if (key == 2)
		move_down(g);
	if (key == 1)
		move_down_left(g);
	if (key == 4)
		move_left(g);
	if (key == 7)
		move_up_left(g);
}


