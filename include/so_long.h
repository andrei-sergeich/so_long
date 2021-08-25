#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include "limits.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
//# include <mlx.h>

typedef struct s_markers
{
	char 	**map;
	int		map_len;
	int		map_wid;
	int		exit;
	int		collect;
	int		pos;
	int		border;
	int		ground;
	int		death;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_hei;
	int		img_wid;
	int		steps;
	int		grades;
	void	*img_hero;
	void	*img_ground;
	void	*img_border;
	void	*img_weapon;
	void	*img_helic_c;
	void	*img_helic_o;
	void	*img_death;
	int		pos_x;
	int		pos_y;
	int		death_x;
	int		death_y;
	int		exit_x;
	int		exit_y;
}	t_markers;

int		main(int argc, char **argv);
void	so_long(int argc, char **argv);

void	argument_checker(int argc, char **argv);
void	init_markers(t_markers *mark);
void	map_width_counter(char *map, t_markers *mark);
void	map_parser(char *map, t_markers *mark);
void	map_checker(t_markers *mark);
void	top_and_bottom_of_map(t_markers *mark);
void	body_of_map(char *line, t_markers *mark);

void	init_game(t_markers *mark);
void	map_filling(t_markers *mark);
void	put_image(char symbol, t_markers *mark, int y, int x);

int		lets_push(int keycode, t_markers *mark);
void	lets_play(int keycode, t_markers *mark);
void	lets_move(t_markers *mark, int x, int y);
void	moving(t_markers *mark, int x, int y);
void	evacuation(t_markers *mark);

int		ft_close(t_markers *mark, char message_code);
int		ft_close_x(t_markers *mark);
char	*check_image(char *path);
void	init_image(t_markers *mark);
void	step_printer(t_markers *mark);

#endif