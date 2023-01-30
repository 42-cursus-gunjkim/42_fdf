/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:49:12 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/30 22:56:45 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_element(char *line, char c)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == c)
			i++;
		line++;
	}
	return (i);
}
//결국 split 할수 밖에 없음 맵이 철저히 공백을 기준으로 구분되어있음 한개인지 두개인지는 아무도 모른다

int	check_map(const char *path, t_vars *var)
{
	char	*tmp;
	int		fd;
	int		height;
	int		width_tmp;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_and_exit(NULL);
	tmp = get_next_line(fd);
	var->map_width = count_element(tmp, ' ');
	while (tmp != NULL)
	{
		height++;
		width_tmp = count_element(tmp, ' ');
		if (var->map_width != width_tmp)
			error_and_exit("Map Error!");
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	var->map_height = height;
	return (0);
}

int	map_parser(const char *path, t_vars *var)
{
	char	*tmp;
	char	**element;
	int		fd;
	int		i_h;
	int		i_w;

	i_h = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_and_exit(NULL);
	while (i_h < var->map_height)
	{
		i_w = 0;
		tmp = get_next_line(fd);
		element = ft_split(tmp, ' ');
		if (element == NULL)
			error_and_exit("split fail");
		while (i_w < var->map_width)
		{
			var->map[i_h * var->map_width + i_w].x = i_w;
			var->map[i_h * var->map_width + i_w].y = i_h;
			var->map[i_h * var->map_width + i_w].z = ft_atoi(element[i_w]);
			//var->map[i_h * var->map_width + i_w].trgb = do something;
		}
		i_h++;
		free(tmp);
		free_double_arr(element);
	}
	return (0);
}

int	map_init(const char *path, t_vars *var)
{
	check_map(path, var);
	var->map = malloc(var->map_height * var->map_width);
	map_parser(path, var);
	return (0);
}
