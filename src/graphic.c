/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 17:40:45 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_pixel	*isomeric(t_map *map, t_camera *camera)
{
	t_pixel	*iso_img;
	int		pixel_num;
	int		i;

	i = 0;
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
		iso_img[i].trgb = map->map[i].trgb;
		i++;
	}
	return (iso_img);
}

void	render(t_map *map, t_camera *camera, t_data *i_plane)
{
	int		w_i;
	int		h_i;
	int		m_i;
	t_pixel	*img;

	h_i = 0;
	img = isomeric(map, camera);
	while (h_i < map->map_h)
	{
		w_i = 0;
		m_i = h_i * map->map_w;
		while (w_i < map->map_w)
		{
			if (m_i == 0 || m_i % map->map_w != map->map_w - 1)
				draw_line(&img[m_i], &img[m_i + 1], camera, i_plane);
			if (h_i != map->map_h - 1)
				draw_line(&img[m_i], &img[m_i + map->map_w], camera, i_plane);
			w_i++;
			m_i++;
		}
		h_i++;
	}
	free(img);
}
