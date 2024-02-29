/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:36 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 20:19:30 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, void *param)
{
	(void)param;
    if (keycode == KEY_ESC) // Define KEY_ESC according to your system
        exit(0); // Close the program
    return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	ft_printf(">>>>The project so_long is inititated.\n");
	if (!valid_map(argc, argv[1], &g))
		return (EXIT_FAILURE);
	g.mlx_ptr = mlx_init();
	if (!g.mlx_ptr)
		return (error(9));
	print_maps(&g);
	game_start(&g);
	mlx_key_hook(g.win_ptr, key_press, NULL);
	mlx_loop(g.mlx_ptr);
	ft_free(&g);
	free_images(&g);
	ft_printf(">>>>The project so_long is finalized succesfully.\n");
	return (0);
}