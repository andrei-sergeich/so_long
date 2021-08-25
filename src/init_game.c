#include "../include/so_long.h"

void	step_printer(t_markers *mark)
{
	char	*count;

	count = ft_itoa(mark->steps);
	put_image('1', mark, 0, 1);
	put_image('1', mark, 0, 0);
	mlx_string_put(mark->mlx, mark->win, 10, 20, 0xadff2f, "Steps:  ");
	mlx_string_put(mark->mlx, mark->win, 80, 20, 0x9acd32, count);
	free(count);
}

void	moving(t_markers *mark, int x, int y)
{
	mark->map[mark->pos_y + y][mark->pos_x + x] = 'P';
	mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_hero, \
										&mark->img_hei, &mark->img_wid);
	mlx_put_image_to_window(mark->mlx, mark->win, mark->img, \
							mark->img_hei * (mark->pos_x + x), \
							mark->img_wid * (mark->pos_y + y));
	mark->map[mark->pos_y][mark->pos_x] = '0';
	mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_ground, \
										&mark->img_hei, &mark->img_wid);
	mlx_put_image_to_window(mark->mlx, mark->win, mark->img, \
							mark->img_hei * mark->pos_x, \
							mark->img_wid * mark->pos_y);
	mark->pos_x = mark->pos_x + x;
	mark->pos_y = mark->pos_y + y;
	mark->steps++;
	step_printer(mark);
}

void	evacuation(t_markers *mark)
{
	int	w;
	int	l;

	w = 0;
	while (mark->map[w])
	{
		l = 0;
		while (mark->map[w][l])
		{
			if (mark->map[w][l] == 'E')
			{
				mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_helic_o, \
												&mark->img_hei, &mark->img_wid);
				mlx_put_image_to_window(mark->mlx, mark->win, mark->img, \
				l * mark->img_hei, w * mark->img_wid);
			}
			l++;
		}
		w++;
	}
}

void	lets_move(t_markers *mark, int x, int y)
{
	if (mark->map[mark->pos_y + y][mark->pos_x + x] != '1')
	{
		if (mark->map[mark->pos_y + y][mark->pos_x + x] == 'D')
			ft_close(mark, 'D');
		else if (mark->map[mark->pos_y + y][mark->pos_x + x] == 'E' \
				&& mark->collect == 0)
			ft_close(mark, 'W');
		else if (mark->map[mark->pos_y + y][mark->pos_x + x] == 'C')
		{
			moving(mark, x, y);
			mark->collect -= 1;
			if (mark->collect == 0)
				evacuation(mark);
		}
		else if (mark->map[mark->pos_y + y][mark->pos_x + x] == '0')
			moving(mark, x, y);
	}
}

int	lets_push(int keycode, t_markers *mark)
{
	if (keycode == 13)
		lets_move(mark, 0, -1);
	else if (keycode == 1)
		lets_move(mark, 0, 1);
	else if (keycode == 0)
		lets_move(mark, -1, 0);
	else if (keycode == 2)
		lets_move(mark, 1, 0);
	else if (keycode == 53)
		ft_close(mark, 'C');
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
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_helic_c, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == 'P')
	{
		mark->pos_x = x;
		mark->pos_y = y;
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_hero, \
											&mark->img_hei, &mark->img_wid);
	}
	if (symbol == 'D')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_death, \
											&mark->img_hei, &mark->img_wid);
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
	mark->mlx = mlx_init();
	mark->win = mlx_new_window(mark->mlx, mark->map_len * 64, \
						mark->map_wid * 64, "So Long!");
	map_filling(mark);
	mlx_hook(mark->win, 2, 0, lets_push, mark);
	mlx_hook(mark->win, 17, 1L << 2, ft_close_x, mark);
	mlx_loop(mark->mlx);
}

// void sleep()
// {
//  int i = 0;
//  int j = 0;
// while (j != 10)
// {

// 	j++;
// }
// while (i != 10)
// {
// 	i++;

// }
// sleep();
// }