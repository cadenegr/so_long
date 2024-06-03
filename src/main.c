/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:36 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/07 14:20:14 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	ft_printf(">>>>The project so_long is inititated.\n");
	if (!valid_map(argc, argv[1], &g))
		return (EXIT_FAILURE);
	g.mlx_ptr = mlx_init();
	if (!g.mlx_ptr)
		return (error(9));
	// print_maps(&g);
	game_start(&g);
	ft_printf("p x: %d and p y: %d\n", g.coordi.p_x, g.coordi.p_y);
	// mlx_hook(g.win_ptr, KeyPress, KeyPressMask, key_press, &g);
	mlx_hook(g.win_ptr, KeyPress, KeyPressMask, key_press, &g);
	// mlx_key_hook(g.win_ptr, key_press, NULL);
	mlx_loop(g.mlx_ptr);
	ft_free(&g);
	free_images(&g);
	ft_printf(">>>>The project so_long is finalized succesfully.\n");
	return (0);
}
