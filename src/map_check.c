/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:35:39 by cadenegr          #+#    #+#             */
/*   Updated: 2024/02/29 18:17:29 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_map(int argc, char *file, t_game *g)
{
	ft_printf(">>Entered function valid_map.\n");
	struct_init(g);
	if (argc != 2)
		return (0);
	if (!ft_strnstr(file, ".ber\0", ft_strlen(file)))
		return (error(1));
	if (!map_reader(file, g))
		return (0);
	if (g->height < 2)
		return (error(3));
	if (g->p != 1 || g->e != 1)
		return (error(5));
	if (!(g->total_collect > 0))
		return (error(6));
	if (!map_maker(file, g))
		return (error(7));
	if (!valid_path(g, g->coordi.p_x, g->coordi.p_y))
		return (error(8));
	ft_printf(">>Exit function valid_map.\n");
	return (1);
}

bool	map_reader(char *file, t_game *g)
{
	char	*line;

	ft_printf(">>Enter map_reader\n");
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
		return (error(2));
	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		g->width = ft_strlen(line);
		g->height++;
		free (line);
	}
	close(g->fd);
	g->fd = -1;
	if (!map_inspect(file, g))
		return (0);
	ft_printf(">>Exit map_reader\n");
	return (1);
}

bool	map_inspect(char *file, t_game *g)
{
	int		i;
	char	*line;

	ft_printf(">>Enter map_inspect\n");
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
		return (error(2));
	i = 0;
	while (1)
	{
		line = get_next_line(g->fd);
		if (!line)
			break ;
		if (!check_line(line, g, i))
		{
			free (line);
			return (error(4));
		}
		g->previous_width = ft_strlen (line);
		free (line);
		if (g->width != g->previous_width)
			return (error(3));
		i++;
	}
	close (g->fd);
	g->fd = -1;
	free (line);
	g->total_collect = g->c;
	g->c = 0;
	ft_printf(">>Exit map_reader\n");
	return (1);
}

bool	check_line(char *line, t_game *g, int row)
{
	int	i;

	ft_printf(">>Enter check_line\n");
	if (row == 0 || row == g->height)
	{
		i = 0;
		while (i != 10)
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	else
		if (line[0] != '1' || line[g->width - 2] != '1')
			return (0);
	check_player_collect_exit(line, g, row);
	ft_printf(">>Exit check_line\n");
	return (1);
}

void	check_player_collect_exit(char *line, t_game *g, int row)
{
	int	i;

	ft_printf(">>Enter check_player_collect_exit\n");
	i = 0;
	while (line[i] != 10)
	{
		if (line[i] == 'P')
		{
			g->coordi.p_x = i;
			g->coordi.p_y = row;
			g->p++;
		}
		if (line[i] == 'C')
			g->c++;
		if (line[i] == 'E')
			g->e++;
		i++;
	}
	ft_printf(">>Exit check_player_collect_exit\n");
}
