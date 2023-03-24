/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:05:01 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 14:09:59 by gunjkim          ###   ########.fr       */
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

int	get_abs_max(t_map *map)
{
	int	i;
	int	num;
	int	max;

	i = 0;
	num = map->map_w * map->map_h;
	max = map->map[i].z;
	while (i < num)
	{
		if (abs(map->map[i].z) > abs(max))
			max = map->map[i].z;
		i++;
	}
	return (max);
}

int	get_height_color(int z, int abs_max)
{
	int	rate;

	if (abs_max == 0)
		return (0xFFFFFF);
	rate = 255 / abs(abs_max);
	z = abs(z);
	if (z > 0)
		return (create_trgb(0, 255 - rate * z, 255 - rate * z, 255));
	else if (z < 0)
		return (create_trgb(0, 255, 255 - rate * z, 255 - rate * z));
	else
		return (0xFFFFFF);
}

void	get_beauty(t_pixel *p0, t_pixel *p1, t_pixel *tmp)
{
	float	rate;

	rate = abs(p0->x - p1->x) + abs(p0->y - p1->y);
	tmp->r = tmp->r + (get_r(p1->trgb) - get_r(p0->trgb)) / rate;
	tmp->b = tmp->b + (get_b(p1->trgb) - get_b(p0->trgb)) / rate;
	tmp->g = tmp->b + (get_g(p1->trgb) - get_g(p0->trgb)) / rate;
	tmp->trgb = create_trgb(0, (int)tmp->r, (int)tmp->g, (int)tmp->b);
}
