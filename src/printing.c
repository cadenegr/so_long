/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:08:58 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 11:10:06 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_maps(t_game *g)
{
	int	i;
	int	j;

	ft_printf("Enter print_maps.\n");
	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (g->map[i][j])
		{
			ft_printf("%c", g->map[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("\n\n");
	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (g->temp_map[i][j])
		{
			ft_printf("%c", g->temp_map[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("Exit print_maps.\n");
}