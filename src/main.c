/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:17:36 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 16:58:39 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	ft_printf(">>>>The project so_long is inititated.\n");
	if (!valid_map(argc, argv[1], &g))
		return (EXIT_FAILURE);
	// print_maps(&g);
	g.mlx_ptr = mlx_init();
	if (!g.mlx_ptr)
		return (error(9));
	game_start(&g);
	ft_free(&g);
	ft_printf(">>>>The project so_long is finalized succesfully.\n");
	return (0);
}