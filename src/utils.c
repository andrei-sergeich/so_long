#include "../include/so_long.h"

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
//	mark->img_hei = 64;
//	mark->img_wid = 64;
//	mark->grades = 0;
	mark->steps = 0;
	mark->img_hero = check_image("./images/hero_an.xpm");
	mark->img_ground = check_image("./images/ground.xpm");
	mark->img_border = check_image("./images/border.xpm");
	mark->img_weapon = check_image("./images/machine_gun.xpm");
	mark->img_helic_c = check_image("./images/helic_c.xpm");
	mark->img_helic_o = check_image("./images/helic_o.xpm");
	mark->img_death = check_image("./images/patrol_1.xpm");
}
