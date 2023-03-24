/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 23:29:09 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

void	isomeric(t_pixel *img, t_camera *camera, int i_max)
{
	int		i;
	int		tmp_x;

	i = 0;
	while (i < i_max)
	{
		tmp_x = img[i].x;
		img[i].x = ((tmp_x - img[i].y) * cos(0.523599)) + camera->offset_w;
		img[i].y = (-img[i].z) + (tmp_x + img[i].y) * sin(0.523599) + camera->offset_h;
		i++;
	}
}

t_pixel	*centered_and_rotate(t_map *map, t_camera *camera)
{
	t_pixel	*img;
	int		i_max;
	int		i;
	int		max;
	int		min;

	i = 0;
	get_min_max(map, &min, &max);
	i_max = map->map_w * map->map_h;
	img = (t_pixel *)malloc(sizeof(t_pixel) * i_max);
	while (i < i_max)
	{
		img[i].x = map->map[i].x * camera->f - (map->map_w * camera->f)/2;
		img[i].y = map->map[i].y * camera->f - (map->map_h * camera->f)/2;
		img[i].z = map->map[i].z * camera->f;
		img[i].h = map->map[i].z;
		rotate_x(&img[i], camera->x_a);
		rotate_y(&img[i], camera->y_a);
		rotate_z(&img[i], camera->z_a);
		if (map->map[i].trgb != -1)
			img[i].trgb = map->map[i].trgb;
		else
			img[i].trgb = get_height_color(img[i].h, min, max);
		i++;
	}
	return (img);
}

void	rotate_x(t_pixel *p, float a)
{
	int	tmp_y;

	tmp_y = p->y;
	p->y = (tmp_y * cos(a) + p->z * sin(a));
	p->z = (-tmp_y * sin(a) + p->z * cos(a));
}

void	rotate_y(t_pixel *p, float a)
{
	int	tmp_x;

		tmp_x = p->x;
		p->x = (tmp_x * cos(a) - p->z * sin(a));
		p->z = (-tmp_x * sin(a) + p->z * cos(a));
}

void	rotate_z(t_pixel *p, float a)
{
	float	tmp_x;

	tmp_x = p->x;
	p->x = (tmp_x * cos(a) - p->y * sin(a));
	p->y = (tmp_x * sin(a) + p->y * cos(a));
}
