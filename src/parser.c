/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:16:41 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/27 17:41:45 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

int	get_hex_value(char c)
{
	int		index;
	char	*hex;

	hex = "0123456789ABCDEF";
	index = 0;
	while (hex[index] != '\0')
	{
		if (hex[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	hex_to_int(char *hex)
{
	int		t;
	int		r;
	int		g;
	int		b;

	t = 0;
	r = get_hex_value(hex[2]) * 16 + get_hex_value(hex[3]);
	g = get_hex_value(hex[4]) * 16 + get_hex_value(hex[5]);
	b = get_hex_value(hex[6]) * 16 + get_hex_value(hex[7]);
	return (r << 16 | g << 8 | b);
}

void	init_point(t_map *map, char **line_element, int h_i)
{
	char	**element_comma;
	int		w_i;
	int		c_i;

	w_i = 0;
	while (w_i < map->m_w)
	{
		c_i = map->m_w * h_i + w_i;
		element_comma = ft_split(line_element[w_i], ',');
		if (element_comma == NULL)
			error_exit("ft_split fail");
		map->map[c_i].x = w_i;
		map->map[c_i].y = h_i;
		map->map[c_i].z = ft_atoi(element_comma[0]);
		if (element_comma[1] != NULL)
			map->map[c_i].trgb = hex_to_int(element_comma[1]);
		else
			map->map[c_i].trgb = -1;
		ft_double_free(element_comma);
		w_i++;
	}
}

void	map_to_point(t_map *map, char *map_path)
{
	char	*line;
	char	**line_element;
	int		i;
	int		map_fd;

	i = 0;
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_exit("map open fail");
	while (i < map->m_h)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			error_exit("gnl fail");
		line_element = ft_split(line, ' ');
		if (line_element == NULL)
			error_exit("ft_split fail");
		init_point(map, line_element, i);
		free(line);
		ft_double_free(line_element);
		i++;
	}
}

void	check_w_h(t_map *map, char *map_path)
{
	int		map_fd;
	char	*line;
	char	**line_element;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_exit("map open fail");
	line = get_next_line(map_fd);
	if (line != NULL)
	{
		line_element = ft_split_white(line);
		while (line_element[map->m_w])
			map->m_w++;
		ft_double_free(line_element);
	}
	while (line != NULL)
	{
		free(line);
		map->m_h++;
		line = get_next_line(map_fd);
	}
	close(map_fd);
}
