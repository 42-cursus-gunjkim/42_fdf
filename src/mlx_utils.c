/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:05:01 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/25 18:18:23 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	is_scope(int x, int y, t_camera *camera)
{
	if (x < 0 || x >= camera->win_w)
		return (0);
	if (y < 0 || y >= camera->win_h)
		return (0);
	return (1);
}

void	get_min_max(t_map *map, int *min, int *max)
{
	int	i;
	int	num;
	int	t_max;
	int	t_min;

	i = 0;
	num = map->map_w * map->map_h;
	t_max = map->map[i].z;
	t_min = map->map[i].z;
	while (i < num)
	{
		if ((map->map[i].z) > t_max)
			t_max = map->map[i].z;
		if ((map->map[i].z) < t_min)
			t_min = map->map[i].z;
		i++;
	}
	*max = t_max;
	*min = t_min;
}

int	render(t_vars *var)
{
	int		w_i;
	int		h_i;
	int		m_i;
	t_pixel	*img;

	h_i = 0;
	projection(var->img, &(var->map), &(var->camera));
	img = var->img;
	var->data.img_plane = mlx_new_image(var->mlx, var->camera.win_w, var->camera.win_h);
	var->data.addr = mlx_get_data_addr(var->data.img_plane, &(var->data.bpp), \
	&(var->data.line_length), &(var->data.endian));
	while (h_i < var->map.map_h)
	{
		w_i = 0;
		m_i = h_i * var->map.map_w;
		while (w_i < var->map.map_w)
		{
			if (m_i == 0 || m_i % var->map.map_w != var->map.map_w - 1)
				draw_line(&img[m_i], &img[m_i + 1], &(var->camera), &(var->data));
			if (h_i != var->map.map_h - 1)
				draw_line(&img[m_i], &img[m_i + var->map.map_w], &(var->camera), &(var->data));
			w_i++;
			m_i++;
		}
		h_i++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->data.img_plane, 0, 0);
	return (1);
}
