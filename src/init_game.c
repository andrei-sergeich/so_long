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

void	put_image(char symbol, t_markers *mark, int y, int x)
{
	if (symbol == '1')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_border, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == '0')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_ground, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == 'C')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_weapon, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == 'E')
	{
		mark->exit_x = x;
		mark->exit_y = y;
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_helic_c, \
											&mark->img_hei, &mark->img_wid);
	}
	if (symbol == 'P')
	{
		mark->pos_x = x;
		mark->pos_y = y;
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_hero, \
											&mark->img_hei, &mark->img_wid);
	}
	if (symbol == 'D')
	{
//		mark->death_x = x;
//		mark->death_y = y;
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_death, \
											&mark->img_hei, &mark->img_wid);
	}
	mlx_put_image_to_window(mark->mlx, mark->win, mark->img, \
							x * mark->img_hei, y * mark->img_wid);
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
			put_image(mark->map[w][l], mark, w, l);
			l++;
		}
		w++;
	}
}

void	init_game(t_markers *mark)
{
//	printf("%d\n", mark->collect);
	mark->mlx = mlx_init();
	mark->win = mlx_new_window(mark->mlx, mark->map_len * 64, \
						mark->map_wid * 64, "So Long!");
	map_filling(mark);
	mlx_hook(mark->win, 2, 0, lets_play, mark);
	mlx_hook(mark->win, 17, 1L << 2, ft_close_x, mark);
	mlx_loop(mark->mlx);
}
