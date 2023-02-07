/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:39:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:51:35 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	make_img(t_vars *var)
{
	size_t	w_i;
	size_t	h_i;
	size_t	m_i;

	h_i = 0;
	while (h_i < var->map_h)
	{
		w_i = 0;
		m_i = h_i * var->map_w;
		while (w_i < var->map_w)
		{
			if (m_i == 0 || m_i % var->map_w != var->map_w - 1)
				draw_line(var->map[m_i], var->map[m_i + 1], var);
			if (h_i != var->map_h - 1)
				draw_line(var->map[m_i], var->map[m_i + var->map_w], var);
			w_i++;
			m_i++;
		}
		h_i++;
	}
}

int	render(t_vars *var)
{
	t_data	img;
	char	*addr;

	img.img = mlx_new_image(var->mlx, var->win_w, var->win_h);
	addr = mlx_get_data_addr(img.img, &(img.bpp), &(img.len), &(img.endian));
	var->data = &img;
	var->data->addr = addr;
	make_img(var);
	mlx_put_image_to_window(var->mlx, var->win, var->data->img, 0, 0);
	mlx_destroy_image(var->mlx, var->data->img);
	return (0);
}
