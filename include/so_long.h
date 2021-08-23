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

#endif