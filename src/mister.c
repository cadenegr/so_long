/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mister.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:28:53 by cadenegr          #+#    #+#             */
/*   Updated: 2024/06/02 22:28:33 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_path(t_game *g, int x, int y)
{
	static int	e;
	static int	c;

	// ft_printf(">>Enter valid_path.\n");
	if (g->temp_map[x][y] == 'X' || g->temp_map[x][y] == '1')
		return (0);
	if (g->temp_map[x][y] == 'E')
		e++;
	if (g->temp_map[x][y] == 'C')
		c++;
	g->temp_map[x][y] = 'X';
	valid_path(g, x + 1, y);//right
	//valid_path(g, x + 1, y + 1);//down-right
	//valid_path(g, x + 1, y - 1);//up-right
	valid_path(g, x, y + 1);//down
	//valid_path(g, x - 1, y + 1);//down left
	valid_path(g, x, y - 1);//up
	valid_path(g, x - 1, y);//left
	//valid_path(g, x - 1, y - 1);//up left
	// ft_printf(">>Exit valid_path.\n");
	if (g->total_collect == c && e == 1)
		return (1);
	return (0);
}
