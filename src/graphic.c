/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 22:48:09 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_pixel	*isomeric(t_map *map, t_camera *camera)
{
	t_pixel	*iso_img;
	int		pixel_num;
	int		i;
	int		abs_max;

	i = 0;
	abs_max = get_abs_max(map);
	pixel_num = map->map_h * map->map_w;
	iso_img = (t_pixel *)malloc(sizeof(t_pixel) * pixel_num);
	if (iso_img == NULL)
		error_exit("malloc fail");
	while (i < pixel_num)
	{
		iso_img[i].x = camera->f * ((map->map[i].x - map->map[i].y) \
		* cos(0.523599)) + camera->offset_w;
		iso_img[i].y = camera->f * (-(map->map[i].z) + \
		(map->map[i].x + map->map[i].y) * sin(0.523599)) + camera->offset_h;
		iso_img[i].height = map->map[i].z;
		if (map->map[i].trgb != -1)
			iso_img[i].trgb = map->map[i].trgb;
		else
			iso_img[i].trgb = get_height_color(iso_img[i].height, abs_max);
		i++;
	}
	return (iso_img);
}

int	render(t_vars *var)
{
	int		w_i;
	int		h_i;
	int		m_i;
	t_pixel	*img;

	h_i = 0;
	img = isomeric(&(var->map), &(var->camera));
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
	free(img);
	mlx_put_image_to_window(var->mlx, var->win, var->data.img_plane, 0, 0);
	return (1);
}
