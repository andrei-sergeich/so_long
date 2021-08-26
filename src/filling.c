/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:10 by cmero             #+#    #+#             */
/*   Updated: 2021/08/26 16:51:05 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
				put_image('E', mark, w, l);
			l++;
		}
		w++;
	}
}

void	put_inactive_images(char symbol, t_markers *mark)
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
		if (mark->collect != 0)
			mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_helic_c, \
												&mark->img_hei, &mark->img_wid);
		else
			mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_helic_o, \
												&mark->img_hei, &mark->img_wid);
	}
}

void	put_active_images(char symbol, t_markers *mark)
{
	if (symbol == 'P')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_hero, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == 'D')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_death, \
											&mark->img_hei, &mark->img_wid);
	if (symbol == 'X')
		mark->img = mlx_xpm_file_to_image(mark->mlx, mark->img_death_2, \
											&mark->img_hei, &mark->img_wid);
}

void	put_image(char symbol, t_markers *mark, int y, int x)
{
	if (symbol == '1' || symbol == '0' || symbol == 'C' || symbol == 'E')
		put_inactive_images(symbol, mark);
	if (symbol == 'P' || symbol == 'D' || symbol == 'X')
	{
		if (symbol == 'P')
		{
			mark->pos_x = x;
			mark->pos_y = y;
		}
		put_active_images(symbol, mark);
	}
	mlx_put_image_to_window(mark->mlx, mark->win, mark->img, \
								x * mark->img_hei, y * mark->img_wid);
}

int	patrol_animation(t_markers *mark)
{
	int	w;
	int	l;

	w = 0;
	if ((double)(clock()) / CLOCKS_PER_SEC - mark->time >= (double)1 / 10)
	{
		mark->frame++;
		mark->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (mark->frame > 49)
		mark->frame = 0;
	while (mark->map[w])
	{
		l = 0;
		while (mark->map[w][l])
		{
			if (mark->map[w][l] == 'D' && mark->frame > 24)
				put_image('D', mark, w, l);
			else if (mark->map[w][l] == 'D' && mark->frame <= 24)
				put_image('X', mark, w, l);
			l++;
		}
		w++;
	}
	return (0);
}
