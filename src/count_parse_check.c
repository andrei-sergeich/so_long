#include "../include/so_long.h"

void	map_width_counter(char *map, t_markers *mark)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error: no such file in directory");
	while (1)
	{
		gnl = get_next_line(fd, &line);
		mark->map_wid += 1;
		free(line);
		if (gnl == 0)
			break ;
		if (gnl == -1)
			ft_error("Error: GNL error");
	}
	close(fd);
}

void	map_parser(char *map, t_markers *mark)
{
	int		it;
	int		fd;
	char	*line;

	it = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error: no such file in directory");
	mark->map = ft_calloc(mark->map_wid + 1, sizeof(char *));
	while (1)
	{
		if (get_next_line(fd, &line) == 0)
		{
			mark->map[it] = ft_strdup(line);
			free(line);
			break ;
		}
		mark->map[it] = ft_strdup(line);
		free(line);
		it++;
	}
	close(fd);
}

void	top_and_bottom_of_map(t_markers *mark)
{
	int	it;

	it = 0;
	if ((int)ft_strlen(mark->map[mark->map_wid - 1]) != mark->map_len)
		ft_error("Error: incorrect shape of the map");
	while (mark->map[0][it])
	{
		if (mark->map[0][it] != '1')
			ft_error("Error: incorrect top of the map");
		it++;
	}
	it = 0;
	while (mark->map[mark->map_wid - 1][it])
	{
		if (mark->map[mark->map_wid - 1][it] != '1')
			ft_error("Error: incorrect bottom of the map");
		it++;
	}
}

void	body_of_map(char *map_line, t_markers *mark)
{
	int	it;

	it = 0;
	if ((int)ft_strlen(map_line) != mark->map_len)
		ft_error("Error: incorrect shape of the map");
	if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
		ft_error("Error: incorrect border of the map");
	while (map_line[it])
	{
		if (map_line[it] == 'E')
			mark->exit += 1;
		else if (map_line[it] == 'C')
			mark->collect += 1;
		else if (map_line[it] == 'P')
			mark->pos += 1;
		else if (map_line[it] == '1')
			mark->border += 1;
		else if (map_line[it] == '0')
			mark->ground += 1;
		else if (map_line[it] == 'D')
			mark->death += 1;
		else
			ft_error("Error: incorrect symbols on the map");
		it++;
	}
}

void	map_checker(t_markers *mark)
{
	int	it;

	it = 1;
	mark->map_len = (int)ft_strlen(mark->map[0]);
	top_and_bottom_of_map(mark);
	while (it < mark->map_wid)
	{
		body_of_map(mark->map[it], mark);
		it++;
	}
	if (mark->exit != 1 || mark->collect == 0 || mark->pos != 1)
		ft_error("Error: incorrect count of required elements on the map");
	if (mark->map_wid > 17 || mark->map_len > 39)
		ft_error("Error: decrease map parameters");
}
