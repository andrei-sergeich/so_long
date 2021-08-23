#include "../include/so_long.h"

int	lets_play(int keycode, t_markers *mark)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mark->mlx, mark->win);
		ft_putendl_fd("You closed window", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_x(t_markers *mark)
{
	mlx_destroy_window(mark->mlx, mark->win);
	ft_putendl_fd("You closed window", 1);
	exit(EXIT_SUCCESS);
}

char	*check_image(char *path)
{
	if (open((path), O_RDONLY) < 0)
		ft_error("Error: no image file in directory");
	return (path);
}

void	init_image(t_markers *mark)
{
	mark->img_hei = 64;
	mark->img_wid = 64;
	mark->steps = 0;
	mark->grades = 0;
	mark->img_hero = check_image("./images/hero.xpm");
	mark->img_ground = check_image("./images/ground.xpm");
	mark->img_wall = check_image("./images/wall.xpm");
	mark->img_weapon = check_image("./images/weapon.xpm");
	mark->img_helic_c = check_image("./images/helic_c.xpm");
	mark->img_helic_o = check_image("./images/helic_o.xpm");
}

void	map_filling(t_markers *mark)
{
	int	w;
	int	l;

	w = 0;
	init_image(mark);
	while (mark->map[w])
	{
		l = 0;
		while (mark->map[w][l])
		{
//			put_image();
			l++;
		}
		w++;
	}
}

void	init_game(t_markers *mark)
{
	mark->mlx = mlx_init();
	mark->win = mlx_new_window(mark->mlx, mark->map_len * 64, \
						mark->map_wid * 64, "So Long!");
	map_filling(mark);
	mlx_hook(mark->win, 2, 0, lets_play, mark);
	mlx_hook(mark->win, 17, 1L << 2, ft_close_x, mark);
	mlx_loop(mark->mlx);
}
