/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:55:23 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 11:01:34 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_maker(char *file, t_game *g)
{
	int		i;
	char	*line;

	ft_printf("Enter map_maker.\n");
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
		return (error(2));
	g->map = (char **)malloc(sizeof(char *) * (g->height + 1));
	if (!g-> map)
		return (0);
	i = 0;
	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		g->map[i] = line;
		i++;
	}
	g->map[g->height] = NULL;
	close (g->fd);
	g->fd = -1;
	free (line);
	ft_printf("Exit map_maker.\n");
	return (make_temp_map(file, g));
}

bool	make_temp_map(char *file, t_game *g)
{
	int		i;
	char	*line;

	ft_printf("Enter make_map.\n");
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
		return (error(2));
	g->temp_map = (char **)malloc(sizeof(char *) * (g->height + 1));
	if (!g->temp_map)
		return (0);
	i = 0;
	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		g->temp_map[i] = line;
		i++;
	}
	g->temp_map[g->height] = NULL;
	close (g->fd);
	g->fd = -1;
	free (line);
	ft_printf("Exit make_temp.\n");
	return (1);
}
