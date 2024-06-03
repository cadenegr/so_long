/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:35:20 by cadenegr          #+#    #+#             */
/*   Updated: 2024/06/02 22:32:07 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct s_map_gen
{
	int		x;
	int		y;
	int		obstacles;
	int		collectabiles;
	char	**map;
	char	**check;
}	t_mg;

void	create_check(t_mg *mg)
{
	int	i;
	int	j;

	mg->check = ((char **)malloc(sizeof(char *) * (mg->x)));
	if (!mg->check)
		return ;
	i = 0;
	while (i < mg->x)
		mg->check[i++] = (char *)malloc(sizeof(char) * mg->y);
	i = 0;
	while (i < mg->x)
	{
		j = 0;
		while (j < mg->y)
		{
			if (j == 0 || j == (mg->y - 1) || i == 0|| i == (mg->x - 1))
				mg->check[i][j] = '1';
			else
				mg->check[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	input_other(t_mg *mg)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < mg->obstacles)
	{
		x = 1 + rand() % (mg->x - 2);
		y = 1 + rand() % (mg->y - 2);
		mg->map[x][y] = '1';
		mg->check[x][y] = '1';
		i++;
	}
	i = 0;
	while (i < mg->collectabiles)
	{
		x = 1 + rand() % (mg->x - 2);
		y = 1 + rand() % (mg->y - 2);
		if ((x != 1 && y != 1) || (x != (mg->x - 2) && y != (mg->y - 2)))
		{
			mg->map[x][y] = 'C';
			mg->check[x][y] = 'C';
			i++;
		}
	}
	mg->map[1][1] = 'P';
	mg->check[1][1] = 'P';
	mg->map[mg->x - 2][mg->y - 2] = 'E';
	mg->check[mg->x - 2][mg->y - 2] = 'E';
}


void	init(char **av, t_mg *mg)
{
		mg->x = atoi(av[1]);
		mg->y = atoi (av[2]);
		mg->collectabiles = atoi (av[3]);
		mg->obstacles = atoi (av[4]);
		mg->map = NULL;
		mg->check = NULL;
}
int	valid_path(t_mg *mg, int x, int y)
{
	static int	e;
	static int	c;

	// ft_printf(">>Enter valid_path.\n");
	if (mg->check[x][y] == 'X' || mg->check[x][y] == '1')
		return (0);
	if (mg->check[x][y] == 'E')
		e++;
	if (mg->check[x][y] == 'C')
		c++;
	mg->check[x][y] = 'X';
	valid_path(mg, x + 1, y);//right
//	valid_path(mg, x + 1, y + 1);//down-right
//	valid_path(mg, x + 1, y - 1);//up-right
	valid_path(mg, x, y + 1);//down
//	valid_path(mg, x - 1, y + 1);//down left
	valid_path(mg, x, y - 1);//up
	valid_path(mg, x - 1, y);//left
//	valid_path(mg, x - 1, y - 1);//up left
	// ft_printf(">>Exit valid_path.\n");
	if (c == mg->collectabiles && e == 1)
		return (1);
	return (0);
}

int	step(t_mg *mg, int x, int y)
{
	if (mg->map[x][y] == 'E')
		return 1;
	if (mg->map[x][y] == '0' && mg->check[x][y] == '.')
	{
		mg->check[x][y] = 'X'; // Mark as visited

// Attempt to move in all directions
        if ((y + 1 < mg->y && step(mg, x, y + 1)) ||
            (x + 1 < mg->x && step(mg, x + 1, y)) ||
            (x - 1 >= 0 && step(mg, x - 1, y)) ||
            (y - 1 >= 0 && step(mg, x, y - 1))) {
            return 1; // Path to home found
        }

		// Backtrack: unmark the visited position if no path found
		mg->check[x][y] = '.';
	}
	return 0; // No path to home from this position
}

void	free_arr(t_mg *mg)
{
	int	i;

	i = 0;
	while (i < mg->x)
	{
		free(mg->map[i]);
		i++;
	}

	i = 0;
	while (i < mg->x)
	{
		free(mg->check[i]);
		i++;
	}
	free(mg->map);
	free(mg->check);
}

int	create_map(t_mg *mg)
{
	int	i;
	int	j;

	mg->map = ((char **)malloc(sizeof(char *) * (mg->x)));
	if (!mg->map)
		return (0);
	i = 0;
	while (i < mg->x)
		mg->map[i++] = (char *)malloc(sizeof(char) * mg->y);
	i = 0;
	while (i < mg->x)
	{
		j = 0;
		while (j < mg->y)
		{
			if (j == 0 || j == (mg->y - 1) || i == 0|| i == (mg->x - 1))
				mg->map[i][j] = '1';
			else
				mg->map[i][j] = '0';
			j++;
		}
		i++;
	}
	create_check(mg);
	input_other(mg);
	if (!valid_path(mg, 1, 1))
	{
		free_arr(mg);
		create_map(mg);
	}
	return (1);
}

void	save_map_in_file(t_mg *mg)
{
	FILE	*fd;
	int	i;
	int	j;

	fd = fopen ("map.ber", "w");
	if (!fd)
	{
		printf("Error making file.\n");
		return ;
	}
	i = 0;
	while (i < mg->x)
	{
		j = 0;
		while (j < mg->y)
		{
			fputc(mg->map[i][j], fd);
			j++;
		}
		fputc('\n', fd);
		i++;
	}
	fclose (fd);
	printf("Map generated and saved in map.ber file\n");
}

int	main (int ac, char **av)
{
	t_mg	mg;

	if (ac != 5)
	{
		printf("Error.\nArgs must be: executable length width collectabiles obstacles\n");
		return (1);
	}
	init(av, &mg);
	srand (time(NULL));
	if (create_map(&mg))
		save_map_in_file(&mg);
	free_arr(&mg);
	return (EXIT_SUCCESS);
}
