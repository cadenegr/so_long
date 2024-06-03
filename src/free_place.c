/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:25:50 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/02 14:38:02 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *g)
{
	int	i;

	ft_printf(">>Entered free.\n");
	if (g->map)
	{
		i = 0;
		while (g->map[i])
		{
			free(g->map[i]);
			i++;
		}
		free(g->map);
	}
	if (g->temp_map)
	{
		i = 0;
		while (g->temp_map[i] != NULL)
		{
			free(g->temp_map[i]);
			i++;
		}
		free(g->temp_map);
	}
	ft_printf(">>Exit free.\n");
}
