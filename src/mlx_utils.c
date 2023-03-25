/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:05:01 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/26 00:36:55 by gunjkim          ###   ########.fr       */
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
	if (x < 0 || x >= camera->w_w)
		return (0);
	if (y < 0 || y >= camera->w_h)
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
	num = map->m_w * map->m_h;
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

void	draw_img(t_pixel *img, t_map *map, t_camera *camera, t_data *data)
{
	int		w_i;
	int		h_i;
	int		m_i;

	h_i = 0;
	while (h_i < map->m_h)
	{
		w_i = 0;
		m_i = h_i * map->m_w;
		while (w_i < map->m_w)
		{
			if (m_i == 0 || m_i % map->m_w != map->m_w - 1)
				draw_line(&img[m_i], &img[m_i + 1], camera, data);
			if (h_i != map->m_h - 1)
				draw_line(&img[m_i], &img[m_i + map->m_w], camera, data);
			w_i++;
			m_i++;
		}
		h_i++;
	}
}

int	render(t_vars *var)
{
	t_pixel	*img;

	projection(var->img, &(var->map), &(var->camera));
	if (var->camera.method == 1)
		isomeric(var->img, &var->camera, var->map.m_h * var->map.m_w);
	else if (var->camera.method == 2)
		parallel(var->img, &var->camera, var->map.m_h * var->map.m_w);
	img = var->img;
	var->data.i_p = mlx_new_image(var->mlx, var->camera.w_w, var->camera.w_h);
	var->data.addr = mlx_get_data_addr(var->data.i_p, &(var->data.bpp), \
	&(var->data.line_length), &(var->data.endian));
	draw_img(var->img, &var->map, &var->camera, &var->data);
	mlx_put_image_to_window(var->mlx, var->win, var->data.i_p, 0, 0);
	return (1);
}
