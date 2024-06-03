/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:37:34 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/07 15:25:05 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *g)
{
	ft_printf(">>>>Enter key_press.\n");
    if (keycode == KEY_ESC)
	{// Define KEY_ESC according to your system
		free_images(g);
		// print_maps(g);
		// ft_free(g);
		exit(0); // Close the program
	}
	if (keycode == KEY_W)
		movement(g, KEY_W);
	if (keycode == KEY_A)
		movement(g, KEY_A);
	if (keycode == KEY_S)
		movement(g, KEY_S);
	if (keycode == KEY_D)
		movement(g, KEY_D);
	ft_printf(">>>>Exit key_press.\n");
    return (0);
}
