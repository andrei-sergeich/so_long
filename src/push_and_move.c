/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:06 by cmero             #+#    #+#             */
/*   Updated: 2021/08/26 14:09:18 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	moving(t_markers *mark, int x, int y)
{
	mark->map[mark->pos_y][mark->pos_x] = '0';
	put_image('0', mark, mark->pos_y, mark->pos_x);
	mark->map[mark->pos_y + y][mark->pos_x + x] = 'P';
	put_image('P', mark, mark->pos_y + y, mark->pos_x + x);
	mark->steps++;
	step_printer(mark);
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
