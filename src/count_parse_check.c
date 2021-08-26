/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_parse_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:47:27 by cmero             #+#    #+#             */
/*   Updated: 2021/08/26 13:47:39 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_width_counter(char *map, t_markers *mark)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error: no such file in directory");
	count = 1;
	while (count == 1)
	{
		count = get_next_line(fd, &line);
		free(line);
		mark->map_wid += 1;
	}
	if (count == -1)
		ft_error("Error: GNL error");
	close(fd);
}

void	map_parser(char *map, t_markers *mark)
{
	int		it;
	int		fd;
	int		count;
	char	*line;

	it = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error: no such file in directory");
	mark->map = ft_calloc(mark->map_wid + 1, sizeof(char *));
	count = 1;
	while (count == 1)
	{
		count = get_next_line(fd, &line);
		mark->map[it] = ft_strdup(line);
		free(line);
		it++;
	}
	if (count == -1)
		ft_error("Error: GNL error");
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
		else if (map_line[it] == '1' || map_line[it] == '0' \
				|| map_line[it] == 'D')
			;
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
	if (mark->exit == 0 || mark->collect == 0 || mark->pos != 1)
		ft_error("Error: incorrect count of required elements on the map");
	if (mark->map_wid > 17 || mark->map_len > 39)
		ft_error("Error: decrease map parameters");
}
