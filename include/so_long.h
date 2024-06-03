/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <neo_dgri@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:43:27 by cadenegr          #+#    #+#             */
/*   Updated: 2024/03/02 13:52:31 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdbool.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_ESC XK_Escape
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define GRASS "./assets/sprities/grass1.xpm"
# define LAVA "./assets/sprities/lava.xpm"
# define B_FR_ONE "./assets/sprities/b_front1.xpm"
# define CELLAR "./assets/sprities/cellar.xpm"
# define COLLECTABILE "./assets/sprities/coll.xpm"

typedef struct s_coordinate
{
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		old_px;
	int		old_py;
}	t_coordi;

typedef struct s_img
{
	void	*cellar_img;
	void	*grass_img;
	void	*lava_img;
	void	*coll_img;
	void	*b_fr_one_img;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**temp_map;
	int			height;
	int			width;//it has the'\n' and '\0' so is -2!
	int			previous_width;
	int			fd;
	int			p;
	int			c;
	int			total_collect;
	int			e;
	int			moves;
	t_coordi	coordi;
	t_img		textures;
}	t_game;

void	struct_init(t_game *g);
bool	valid_map(int argc, char *file, t_game *g);
bool	map_reader(char *file, t_game *g);
bool	map_inspect(char *line, t_game *g);
bool	check_line(char *line, t_game *g, int row);
bool	check_last_line(char *line, t_game *g);
void	check_player_collect_exit(char *line, t_game *g, int row);
int		error(int type);
bool	map_maker(char *file, t_game *g);

bool	make_temp_map(char *file, t_game *g);

bool	valid_path(t_game *g, int x, int y);

void	movement(t_game *g, int key);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_right(t_game *g);
void	move_left(t_game *g);
void	move_up_right(t_game *g);
void	move_down_left(t_game *g);
void	move_down_right(t_game *g);
void	move_up_left(t_game *g);

void	print_maps(t_game *g);

void	start_img(t_game *g);
void	game_start(t_game *g);
void	insert(t_game *g, int x, int y);
void	finish(t_game *g);
int		key_press(int keycode, t_game *g);
void	free_images(t_game *g);
void	ft_free(t_game *g);
#endif
