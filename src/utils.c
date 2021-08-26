/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:24 by cmero             #+#    #+#             */
/*   Updated: 2021/08/26 14:08:38 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	step_printer(t_markers *mark)
{
	char	*count;

	count = ft_itoa(mark->steps);
	put_image('1', mark, 0, 1);
	put_image('1', mark, 0, 0);
	mlx_string_put(mark->mlx, mark->win, 10, 20, 0xadff2f, "Steps:  ");
	mlx_string_put(mark->mlx, mark->win, 80, 20, 0x9acd32, count);
	ft_putstr_fd("Steps:  ", 1);
	ft_putendl_fd(count, 1);
	free(count);
}

int	ft_close(t_markers *mark, char message_code)
{
	mlx_destroy_window(mark->mlx, mark->win);
	if (message_code == 'C')
		ft_putendl_fd("NOOOOOOO... You closed window :.(", 1);
	else if (message_code == 'W')
		ft_putendl_fd("CONGRATULATIONS! YOU WIN!!!", 1);
	else if (message_code == 'D')
		ft_putendl_fd("YOU WERE KILLED BY AN ENEMY PATROL", 1);
	exit(EXIT_SUCCESS);
}

int	ft_close_x(t_markers *mark)
{
	mlx_destroy_window(mark->mlx, mark->win);
	ft_putendl_fd("NOOOOOOO... You closed window :.(", 1);
	exit(EXIT_SUCCESS);
}

char	*check_image(char *path)
{
	if (open((path), O_RDONLY) < 0)
		ft_error("Error: no image file in directory");
	return (path);
}

void	init_markers(t_markers	*mark)
{
	mark->map_len = 0;
	mark->map_wid = 0;
	mark->exit = 0;
	mark->collect = 0;
	mark->pos = 0;
	mark->img_hei = 64;
	mark->img_wid = 64;
	mark->steps = 0;
	mark->frame = 0;
	mark->time = 0;
	mark->img_hero = check_image("./images/hero.xpm");
	mark->img_ground = check_image("./images/ground.xpm");
	mark->img_border = check_image("./images/border.xpm");
	mark->img_weapon = check_image("./images/machine_gun.xpm");
	mark->img_helic_c = check_image("./images/helic_c.xpm");
	mark->img_helic_o = check_image("./images/helic_o.xpm");
	mark->img_death = check_image("./images/patrol_1.xpm");
	mark->img_death_2 = check_image("./images/patrol_2.xpm");
}
