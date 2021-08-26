/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:20 by cmero             #+#    #+#             */
/*   Updated: 2021/08/26 16:51:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <time.h>
# include "limits.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_markers
{
	char	**map;
	int		map_len;
	int		map_wid;
	int		exit;
	int		collect;
	int		pos;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_hei;
	int		img_wid;
	int		steps;
	int		frame;
	int		time;
	void	*img_hero;
	void	*img_ground;
	void	*img_border;
	void	*img_weapon;
	void	*img_helic_c;
	void	*img_helic_o;
	void	*img_death;
	void	*img_death_2;
	int		pos_x;
	int		pos_y;
}	t_markers;

int		main(int argc, char **argv);
void	argument_checker(int argc, char **argv);
void	so_long(char *map);

void	map_width_counter(char *map, t_markers *mark);
void	map_parser(char *map, t_markers *mark);
void	map_checker(t_markers *mark);
void	top_and_bottom_of_map(t_markers *mark);
void	body_of_map(char *line, t_markers *mark);

void	init_game(t_markers *mark);
void	map_filling(t_markers *mark);
void	put_image(char symbol, t_markers *mark, int y, int x);
int		patrol_animation(t_markers *mark);
void	evacuation(t_markers *mark);

int		lets_push(int keycode, t_markers *mark);
void	lets_move(t_markers *mark, int x, int y);
void	moving(t_markers *mark, int x, int y);

void	init_markers(t_markers *mark);
char	*check_image(char *path);
void	step_printer(t_markers *mark);
int		ft_close(t_markers *mark, char message_code);
int		ft_close_x(t_markers *mark);

#endif