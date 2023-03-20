/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:16:41 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/20 16:46:15 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/error.h"
#include "../include/util.h"
#include "../libft/libft.h"

int	get_num_element(char *line)
{
	int		index;
	char	**line_element;

	index = 0;
	line_element = ft_split(line, ' ');
	while (line_element[index] != NULL)
		index++;
	ft_double_free(line_element);
	return (index);
}

int	map_valid_check(int map_fd, int *m_w, int *m_h)
{
	char	*line;
	int		m_w_tmp;

	line = get_next_line(map_fd);
	*m_h = 0;
	*m_w = -1;
	while (line != NULL)
	{
		m_w_tmp = get_num_element(line);
		free(line);
		if (*m_w == -1)
			*m_w = m_w_tmp;
		if (*m_w != m_w_tmp)
			return (0);
		(*m_h)++;
		line = get_next_line(map_fd);
	}
	return (1);
}

void	map_to_point(t_point *map, int map_fd, int m_w, int m_h)
{
	char	*line;
	char	**line_element;
	char	**element_comma;
	int		h_i;
	int		w_i;

	h_i = 0;
	while (h_i < m_h)
	{
		line = get_next_line(map_fd);
		line_element = ft_split(line, ' ');
		if (line_element == NULL)
			error_exit("ft_split fail");
		w_i = 0;
		while (w_i < m_w)
		{
			element_comma = ft_split(line_element[w_i], ',');
			if (element_comma == NULL)
				error_exit("ft_split fail");
			map[m_w * h_i + w_i].x = w_i;
			map[m_w * h_i + w_i].y = h_i;	
			map[m_w * h_i + w_i].z = ft_atoi(element_comma[0]);
			if (element_comma[1] == NULL)
				map[m_w * h_i + w_i].trgb = -1;
			else
				map[m_w * h_i + w_i].trgb = hex_to_int(element_comma[1]);
			ft_double_free(element_comma);
			w_i++;
		}
		free(line);
		ft_double_free(line_element);
		h_i++;
	}
}

t_point	*parse_map(char *map_path)
{
	int		map_fd;
	int		m_w;
	int		m_h;
	t_point	*map;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_exit("map file open fail");
	if (!map_valid_check(map_fd, &m_w, &m_h))
		error_exit("map is invalid");
	map = (t_point *)malloc(sizeof(t_point) * m_w * m_h);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_exit("map file open fail");
	map_to_point(map, map_fd, m_w, m_h);
	return (map);
}