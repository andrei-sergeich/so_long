#include "../include/so_long.h"

void	init_markers(t_markers	*mark)
{
	mark->map_len = 0;
	mark->map_wid = 0;
	mark->exit = 0;
	mark->collect = 0;
	mark->pos = 0;
	mark->border = 0;
	mark->ground = 0;
}

void	argument_checker(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Error: no map");
	if (argc > 2)
		ft_error("Error: too many arguments");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Error: incorrect extension");
	}
	else
		ft_error("Error: incorrect extension");
}

void	so_long(int argc, char **argv)
{
	t_markers	mark;

	argument_checker(argc, argv);
	init_markers(&mark);
	map_width_counter(argv[1], &mark);
	map_parser(argv[1], &mark);
	map_checker(&mark);
	init_game(&mark);
}
